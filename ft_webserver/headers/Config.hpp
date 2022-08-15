#pragma once
#include <map>
#include <set>
#include <list>
#include <stack>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>

#include "logger/Log.h"
#include "utils.hpp"

/*
listen(addr): ip address for socet, string, default 0.0.0.0
port: port for socet, unsigned short int 0 - 65535, default 80
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
    int         index_fd;
    struct stat index_fd_st;
    bool        autoindex;
    bool        file_upload;
    size_t      client_max_body_size;
    std::string cgi_pass;

    Location(void)
    {
        methods = utl::GET;
        index_fd = 0;
        autoindex = true;
        file_upload = false;
        client_max_body_size = 1024 * 1024;
    }

    Location(const Location &inst){*this = inst;}
    ~Location(void){if (index_fd) close(index_fd);}

    Location    &operator=(const Location &inst)
    {
        if (this == &inst)
            return *this;
        methods = inst.methods;
        returns = returns_t(inst.returns);
        root = inst.root;
        index = inst.index;
        index_fd = inst.index_fd;
        index_fd_st = inst.index_fd_st;
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
    int             num;
    std::string     addr;
    short_t         port;
    bool            is_default;
    server_names_t  server_names;
    error_pages_t   error_pages;
    size_t          client_max_body_size;
    location_t      locs;

    Config(void)
    {
        addr = "0.0.0.0";
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
        addr = inst.addr;
        port = inst.port;
        is_default = inst.is_default;
        server_names = server_names_t(inst.server_names);
        error_pages = error_pages_t(inst.error_pages);
        client_max_body_size = inst.client_max_body_size;
        locs = location_t(inst.locs);
        return *this;
    }

    std::string &getLocIndex(location_t::iterator it)
    {
        struct stat st;
        logger::Log &log = logger::Log::getInst();

        if (fstat(it->second.index_fd, &st) != 0)
        {
            log(logger::ERROR,
                "Location %s, fstat %s", it->first.c_str(), strerror(errno));
            return it->second.index;
        }
        if (st.st_mtim > it->second.index_fd_st.st_mtim)
        {
            it->second.index_fd_st = st;
            log(logger::INFO,
                "Location %s, index file was changed, reread it.",
                    it->first.c_str());
            if (lseek(it->second.index_fd, 0, SEEK_SET) < 0)
            {
                log(logger::ERROR, "Location, %s, lseek %s", it->first.c_str(),
                    strerror(errno));
                return it->second.index;
            }
            int res = utl::readFileToString(it->second.index_fd, it->second.index);
            if (res < 0)
                log(logger::ERROR,
                    "Location, %s, read %s", it->first.c_str(), strerror(errno));
        }
        return it->second.index;
    }

    void    clear(void)
    {
        *this = Config();
    }
};

//void	tokenizeFile(s)

bool    getNextConfig(std::ifstream &config_file, Config *conf)
{
    static int count = 0;
    logger::Log &log = logger::Log::getInst();
	std::string token;
	std::list<std::string> tokenList;
	int braces = 0;

    if (count > 0)
        return false;
    if (conf == NULL)
    {
        log(logger::ERROR, "getNextConfig, conf pointer is null");
        exit(EXIT_FAILURE);
    }
    conf->clear();
	for (std::string line; std::getline(config_file, line); ) {
		token.clear();
		for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
			if (std::isspace(*it) || *it == '#' || *it == ';') {
				if (!token.empty()) {
					tokenList.push_back(token);
					token.clear();
				}
				if (*it == '#')
					break;
				continue;
			}
			token.push_back(*it);
		}
		if (!token.empty()) {
			if (token == "{") {
				braces++;
			}
			if (token == "}")
				braces--;
			if (braces == 0) {
				break;
			}
		}
	}
//	for(std::list<string>::iterator it = tokenList.begin(); it != tokenList.end(); ++it){
//		if (*it != "server")
//			log(logger::ERROR, "server token not found in file");
//		if (*it == "listen")
//			conf->addr = *(++it);
//		if (*it == "port")
//	}
	std::list<std::string>::iterator findIter;
	findIter = std::find(tokenList.begin(), tokenList.end(), "server");
	conf->addr = *(++findIter);
	findIter = std::find(tokenList.begin(), tokenList.end(), "port");
//	conf->port = *(++findIter);
//	findIter = std::find(tokenList.begin(), tokenList.end(), "client_max_body_size");
//	conf->client_max_body_size = *(++findIter);
//	findIter = std::find(tokenList.begin(), tokenList.end(), "mime_conf_path");
	count++;
	return true;
}

//			if (line == "server")
//			std::cout << line << std::endl;
//	}
//    if (count == 0)
//    {
//        conf->addr = "127.0.0.1";
//        conf->port = 80;
//        conf->is_default = true;
//        conf->locs["/"].index = "README.md";
//    }
//    else
//    {
//        conf->addr = "127.0.0.1";
//        conf->port = 8081;
//        conf->locs["/"].index = "makefile.srcs";
//    }}

struct lessCfg
{
    bool    operator()(const cfg::Config &f, const cfg::Config &s)
    {
        if (f.is_default)
            return false;
        else if (s.is_default)
            return true;
        else
            return f.num < s.num;
    }
};


}
