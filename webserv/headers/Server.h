/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/05 16:24:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <arpa/inet.h>

#include "logger/Log.h"

#define DEFCFG "./default.cfg"

class Server
{
typedef std::map<std::string, std::string>  t_srv_cfg;
typedef std::map<std::string, t_srv_cfg>    t_srvs_cfg;
typedef std::map<int, t_srvs_cfg>           t_listens;
typedef std::map<in_addr_t, t_listens>      t_srvs;

private:
    std::string                        cfg_file;
    std::map<std::string, std::string> mime_types;
    t_srvs                             srvs;

private:
    void    parseCfg(void);

public:
    Server(char **argv);
    ~Server(void);
};

in_addr_t    aton(std::string cp);
char        *ntoa(in_addr_t in_addr);

