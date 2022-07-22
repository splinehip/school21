#pragma once
#include <map>
#include <set>
#include <sys/types.h>
#include <sys/stat.h>
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

static const int POST = 0x01;
static const int GET = 0x02;
static const int PUT = 0x04;
static const int DELETE = 0x08;

short_t  httpMethod(const std::string &str);


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
        methods = GET;
        autoindex = true;
        file_upload = false;
        client_max_body_size = 1024 * 1024;
    }

    Location(const Location &inst){*this = inst;}
    ~Location(void){close(index_fd);}

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
};

short_t  httpMethod(const std::string &str)
{
    if (str == "POST")
        return POST;
    if (str == "GET")
        return GET;
    if (str == "PUT")
        return PUT;
    if (str == "DELETE")
        return DELETE;
    return 0;
}

}
