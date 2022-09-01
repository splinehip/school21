#pragma once
#include <map>
#include <set>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#include "logger/Log.h"
#include "utils.hpp"

/*
listen(addr): ip address for socet, string, default 0.0.0.0
port: port for socet, unsigned short int 1 - 65535, default 80
default: flag for default server, bool turned off by default
server_names: fqdn, std::set<std::string>
error_pages: http_error_code, path_to_html_file: std::map<short_t, std::string>
client_max_body_size: max szie for request body, size_t default 1Mb

Location:
methods: available http methods, short_t: 4  POST GET PUT DELETE default GET
return: http redirects, redirect_code, new_uri, std::map<short_t, std::string>
root: root folder, path_to_folder, std::string
index: default index file, path_to_file, std::string
autoindex: show/not directories, bool turned on by default
file_upload: available file upload, bool turned off by default
cgi_pass: path to cgi binary, std::string full_path_to_cgi
*/

namespace cfg
{
static const int PORT_MIN = 1;
static const int PORT_MAX = 65535;
static const int HTTP_CODE_MIN = 100;
static const int HTTP_CODE_MAX = 599;

static const std::string dirArr[] = {"listen", "port", "server_name",
                                     "error_page", "client_max_body_size",
                                     "mime_conf_path", "location"};
static const std::string UDirArr[] = {"server","listen","port","server_name",
                                        "client_max_body_size","mime_conf_path"};

struct Location;

typedef unsigned short int                  short_t;
typedef std::map<short_t, std::string>      returns_t;
typedef std::set<std::string>               server_names_t;
typedef std::map<short_t, std::string>      error_pages_t;
typedef std::map<std::string, Location>     location_t;


struct Location
{
    short_t     methods: 4;
    returns_t   returns;
    std::string root;
    std::string index;
    int         fd_index;
    struct stat st_fd_index;
    bool        autoindex;
    bool        file_upload;
    size_t      client_max_body_size;
    std::string cgi_pass;

    Location(void)
    {
        methods = utl::GET;
        fd_index = 0;
        autoindex = true;
        file_upload = false;
        client_max_body_size = 1024 * 1024;
    }

    Location(const Location &inst){*this = inst;}
    ~Location(void){if (fd_index) close(fd_index);}

    Location    &operator=(const Location &inst)
    {
        if (this == &inst)
            return *this;
        methods = inst.methods;
        returns = returns_t(inst.returns);
        root = inst.root;
        index = inst.index;
        fd_index = inst.fd_index;
        st_fd_index = inst.st_fd_index;
        autoindex = inst.autoindex;
        file_upload = inst.file_upload;
        client_max_body_size = inst.client_max_body_size;
        cgi_pass = inst.cgi_pass;
        return *this;
    }
};


class Config
{
public:
    int             id;
    in_addr         addr;
    short_t         port;
    bool            is_default;
    server_names_t  server_names;
    error_pages_t   error_pages;
    size_t          client_max_body_size;
    location_t      locs;

    Config(void)
    {
        id = 0;
        addr.s_addr = 0;
        port = 80;
        is_default = false;
        client_max_body_size = 1024 * 1024;

    }

    Config(const Config &inst){*this = inst;}
    ~Config(void){}

    Config  &operator=(const Config &inst)
    {
        if (this == &inst)
            return *this;
        id = inst.id;
        addr = inst.addr;
        port = inst.port;
        is_default = inst.is_default;
        server_names = server_names_t(inst.server_names);
        error_pages = error_pages_t(inst.error_pages);
        client_max_body_size = inst.client_max_body_size;
        locs = location_t(inst.locs);
        return *this;
    }

    void    setAddr(const std::string &addr)
    {
        logger::Log &log = logger::Log::getInst();

        if (inet_aton(addr.c_str(), &this->addr) == false)
        {
            log(logger::ERROR,
                "Server::setAddr, invalid address: %s", addr.c_str());
            exit(EXIT_FAILURE);
        }
    }

    void    setAddr(const std::vector<std::string> &strs) {
        logger::Log &log = logger::Log::getInst();
        if (strs.size() > 1) {
            log(logger::ERROR, "Wrong format in configuration file: waiting for \
single token after \"listen\"");
            exit(EXIT_FAILURE);
        }
        setAddr(strs[0]);
        return;
    }

    void    setPort(const std::string &port)
    {
        logger::Log &log = logger::Log::getInst();
        int port_val = 0;

        std::istringstream s(port);
        s >> port_val;
        if (port_val < PORT_MIN || port_val > PORT_MAX)
        {
            log(logger::ERROR, "Port %s out of range %i - %i",
                port.c_str(), PORT_MIN, PORT_MAX);
            exit(EXIT_FAILURE);
        }
        this->port = port_val;
    }

    void    setPort(const std::vector<std::string> &strs) {
        logger::Log &log = logger::Log::getInst();
        if (strs.size() > 1) {
            log(logger::ERROR, "Wrong format in configuration file: waiting for \
single token after \"port\"");
            exit(EXIT_FAILURE);
        }
        setPort(strs[0]);
        return;
    }

    void    setErrorPage(const std::string &code, const std::string &path)
    {
        logger::Log &log = logger::Log::getInst();

        int code_val = 0;
        std::istringstream s(code);

        std::ifstream   f;
        std::string     str;
        std::string     page;

        s >> code_val;
        if (code_val < HTTP_CODE_MIN || code_val > HTTP_CODE_MAX)
        {
            log(logger::ERROR,
                "setErrorPage: http code %s out of range: %i - %i",
                    code.c_str(), HTTP_CODE_MIN, HTTP_CODE_MAX);
            exit(EXIT_FAILURE);
        }
        f.open(path.c_str());
        if (f.is_open() == false)
        {
            log(logger::ERROR, "setErrorPage: file %s, open error: %s",
                path.c_str(), strerror(errno));
            exit(EXIT_FAILURE);
        }
        while (getline(f, str))
        {
            page.append(str.append("\n"));
        }
        f.close();
        error_pages[code_val] = page;
    }

    void    addErrorPage(const std::vector<std::string> &strs) {
        logger::Log &log = logger::Log::getInst();
        if (strs.size() != 2) {
            log(logger::ERROR, "Wrong format in configuration file: waiting for\
two parameters after \"error_page\"");
            exit(EXIT_FAILURE);
        }
        setErrorPage(strs[0], strs[1]);
        return;
    }

    void    setServerNames(const std::string &names)
    {
        std::string name;
        std::istringstream s(names);

        while (s >> name)
        {
            server_names.insert(name);
        }
    }

    void    setServerName(const std::string &name)
    {
        server_names.insert(name);
    }

    void    setServerNames(const std::vector<std::string> &strs) {
        std::vector<std::string>::const_iterator it = strs.begin();
        for (; it != strs.end(); ++it)
            setServerName(*it);
        return;
    }

    void    setClientMaxBody(const std::vector<std::string> &strs) {
        (void )strs;
        return;
    }

    void    addLocation(const std::vector<std::string> &strs) {
        (void )strs;
        return;
    }

    void    setMimeConfPath(const std::vector<std::string> &strs) {
        (void )strs;
        return;
    }

    std::string &getLocIndex(location_t::iterator it)
    {
        struct stat st;
        logger::Log &log = logger::Log::getInst();

        if (fstat(it->second.fd_index, &st) != 0)
        {
            log(logger::ERROR,
                "Location %s, fstat %s", it->first.c_str(), strerror(errno));
            return it->second.index;
        }
        if (st.st_mtim > it->second.st_fd_index.st_mtim)
        {
            it->second.st_fd_index = st;
            log(logger::INFO,
                "Location %s, index file was changed, reread it.",
                    it->first.c_str());
            if (lseek(it->second.fd_index, 0, SEEK_SET) < 0)
            {
                log(logger::ERROR, "Location, %s, lseek %s", it->first.c_str(),
                    strerror(errno));
                return it->second.index;
            }
            int res = utl::readFileToString(it->second.fd_index, it->second.index);
            if (res < 0)
            {
                log(logger::ERROR,
                    "Location, %s, read %s", it->first.c_str(), strerror(errno));
            }
        }
        return it->second.index;
    }

    void    clear(void)
    {
        *this = Config();
    }
};

bool    setAttributesFromTokens(
    const std::vector<std::string> &tokenList, Config *conf)
{
    logger::Log &log = logger::Log::getInst();

    static const std::vector<std::string>
    directives(dirArr, dirArr + sizeof(dirArr) / sizeof(dirArr[0]));

    static const std::vector<std::string>
    uniqueDirectives(UDirArr, UDirArr + sizeof(UDirArr) / sizeof(UDirArr[0]));

    typedef void(Config::*setters)(const std::vector<std::string> &arg);
    setters setters_ptr[7] = {&Config::setAddr, &Config::setPort,
                              &Config::setServerNames, &Config::addErrorPage,
                              &Config::setClientMaxBody, &Config::setMimeConfPath,
                              &Config::addLocation};

    if (tokenList[0] != "server")
    {
        log(logger::ERROR, "server token not found in file");
        return false;
    }

    for (long unsigned int i = 1; i < tokenList.size(); ++i)
    {
        std::vector<std::string>::const_iterator
        itFind = std::find(directives.begin(), directives.end(), tokenList[i++]);
        if (itFind != directives.end())
        {
            std::vector<std::string> strs;
            while (std::find(directives.begin(), directives.end(),
                    tokenList[i]) == directives.end() && i < tokenList.size())
            {
                strs.push_back(tokenList[i++]);
            }
            i--;
            (conf->*setters_ptr[itFind - directives.begin()])(strs);
        }
    }
    return true;
}

bool    getNextConfig(std::ifstream &config_file, Config *conf)
{
    static int count = 0;
    logger::Log &log = logger::Log::getInst();
    std::string token;
    std::vector<std::string> tokenList;
    int braces = 0;

    if (count > 0)
        return false;
    if (conf == NULL)
    {
        log(logger::ERROR, "getNextConfig, conf pointer is null");
        exit(EXIT_FAILURE);
    }
    conf->clear();
    if (config_file.eof())
        return false;
    for (std::string line; std::getline(config_file, line); )
    {
        token.clear();
        for (std::string::iterator it = line.begin(); it != line.end(); ++it)
        {
            if (std::isspace(*it) || *it == '#' || *it == ';')
            {
                if (!token.empty())
                {
                    tokenList.push_back(token);
                    token.clear();
                }
                if (*it == '#')
                    break;
                continue;
            }
            token.push_back(*it);
        }
        if (!token.empty())
        {
            if (token == "{")
                braces++;
            else if (token == "}")
                braces--;
            else
                tokenList.push_back(token);
            if (braces == 0)
            {
                break;
            }
        }
    }
    conf->id = count;
    return setAttributesFromTokens(tokenList, conf);
}

struct lessCfg
{
    bool    operator()(const cfg::Config &f, const cfg::Config &s)
    {
        if (f.is_default)
            return false;
        else if (s.is_default)
            return true;
        else
            return f.id < s.id;
    }
};

}
