/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/17 12:24:54 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <set>
#include <arpa/inet.h>

#include "logger/Log.h"

#define DEFCFG "./default.cfg"

namespace srv
{
typedef std::map<std::string, std::string>          t_cfg;
typedef std::map<std::string, t_cfg>                t_cfgs;
typedef std::map<std::string, t_cfgs *>             t_name_srvs;
typedef std::map<int, struct Cfg>                   t_ports;
typedef std::map<in_addr_t, t_ports>                t_srvs;

typedef std::map<std::string, std::string>          t_mime;

struct Cfg
{
    t_name_srvs name_srvs;

    ~Cfg(void);
    t_cfgs   &operator[](const std::string &key);
    t_cfgs   &addAlterName(const std::string &name_server,
                const std::string &alter_name_server);
};

class Server
{
private:
    std::string cfg_file;
    t_mime      mime_types;
    t_srvs      srvs;

private:
    void    parseCfg(void);

public:
    Server(char **argv);
    ~Server(void);

    t_ports             &operator[](const in_addr_t &key);
    t_srvs::iterator    find(const in_addr_t &key);
    t_srvs::iterator    begin(void);
    t_srvs::iterator    end(void);

};

in_addr_t    aton(std::string cp);
char        *ntoa(in_addr_t in_addr);
}
