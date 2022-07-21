#pragma once
#include <map>
#include <set>

#include "logger/Log.h"

/*
listen(addr): ip address for socet, string 0.0.0.0
port: port for socet, unsigned short int 0 - 65535
default: flag for default server, bool turned off by default
server_names: fqdn, std::set<std::string>
error_pages: http_error_code, path_to_html_file: std::map<short_t, std::string>
client_max_body_size: max szie for request body, size_t default 1Mb

Location:
methods: available http methods, std::set<std::string>  POST GET PUT DELETE
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
typedef std::set<std::string>               methods_t;
typedef std::map<short_t, std::string>      returns_t;
typedef std::set<std::string>               server_names_t;
typedef std::map<short_t, std::string>      error_pages_t;
typedef std::map<std::string, Location>     location_t;



struct Location
{
    methods_t   methods;
    returns_t   returns;
    std::string root;
    std::string index;
    bool        autoindex;
    bool        file_upload;
    size_t      client_max_body_size;
    std::string cgi_pass;

    Location(void)
    {
        autoindex = true;
        file_upload = false;
        client_max_body_size = 1024 * 1024;
    }

    Location(const Location &inst){*this = inst;}
    ~Location(void);

    Location    &operator=(const Location &inst)
    {
        if (this == &inst)
            return *this;
        methods = methods_t(inst.methods);
        returns = returns_t(inst.returns);
        root = inst.root;
        index = inst.index;
        autoindex = inst.autoindex;
        file_upload = inst.file_upload;
        client_max_body_size = inst.client_max_body_size;
        cgi_pass = inst.cgi_pass;
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
};

}
