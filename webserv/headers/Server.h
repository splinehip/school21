/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/16 18:05:47 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <set>
#include <arpa/inet.h>

#include "logger/Log.h"

#define DEFCFG "./default.cfg"

class Server
{
struct Cfg;
typedef std::map<std::string, std::string>          t_cfg;
typedef std::map<std::string, t_cfg>                t_cfgs;
typedef std::map<std::string, t_cfgs *>             t_name_srvs;
typedef std::map<int, struct Cfg>                   t_listen_ports;
typedef std::map<in_addr_t, t_listen_ports>         t_srvs;

typedef std::map<std::string, std::string>          t_mime;

private:
    std::string cfg_file;
    t_mime      mime_types;
    t_srvs      srvs;

private:
    void    parseCfg(void);

public:
    Server(char **argv);
    ~Server(void);
};

struct Server::Cfg
{
    t_name_srvs name_srvs;

    ~Cfg(void);
    t_cfgs   &operator[](const std::string &key);
    t_cfgs   &addAlterName(const std::string &name_server,
                const std::string &alter_name_server);
};

in_addr_t    aton(std::string cp);
char        *ntoa(in_addr_t in_addr);
