/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:41:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/07/25 17:52:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <set>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Config.hpp"
#include "logger/Log.h"

namespace srv
{
class Server;

typedef std::map<in_port_t, Server>         m_srv_t;
typedef std::map<in_addr_t, m_srv_t>        m_srvs_t;
typedef std::set<cfg::Config, cfg::lessCfg> cfgs_t;

class Server
{
public:
    int     listenSocket;
    cfgs_t  cfgs;

public:
    Server(void){};
    ~Server(void){};

    void    insert_conf(cfg::Config &conf)
    {
        cfgs.insert(conf);
    }

    int initLisetnSocket(void)
    {
        return true;
    }

};

m_srvs_t  initServers(const std::string &cfg_file)
{
    int         fd;
    m_srvs_t    srvs;
    cfg::Config conf;
    in_addr     addr;
    logger::Log &log = logger::Log::getInst();

    fd = open(cfg_file.c_str(), O_RDONLY);
    if (fd < 0)
    {
        log(logger::ERROR, "Config file open error: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while(cfg::getNextConfig(fd, &conf))
    {
        if (inet_aton(conf.addr.c_str(), &addr) == false)
        {
            log(logger::ERROR,
                "initServers, invalid address: %s", conf.addr.c_str());
            exit(EXIT_FAILURE);
        }
        srvs[addr.s_addr][htons(conf.port)].insert_conf(conf);
    }
    m_srvs_t::iterator it = srvs.begin();
    while (it != srvs.end())
    {
        const in_addr_t &address = it->first;
        const in_port_t &port = it->second.begin()->first;
        srvs[address][port].initLisetnSocket();
        it++;
    }
    close(fd);
    return srvs;
}

}
