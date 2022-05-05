/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/05 16:44:14 by cflorind         ###   ########.fr       */
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
typedef std::map<std::string, std::string>  t_mime;

typedef std::map<std::string, std::string>  t_cfg;
typedef std::map<std::string, t_cfg>        t_name_srvs;
typedef std::map<int, t_name_srvs>          t_listen_srvs;
typedef std::map<in_addr_t, t_listen_srvs>  t_srvs;

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

in_addr_t    aton(std::string cp);
char        *ntoa(in_addr_t in_addr);

