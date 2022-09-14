/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:41:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/09/14 10:27:20 by cflorind         ###   ########.fr       */
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

    const cfg::Config operator[](const std::string key)
    {
        cfgs_t::iterator it = cfgs.begin();
        cfgs_t::iterator end = cfgs.end();
        while (it != end)
        {
            if (it->hasServerName(key))
            {
                return *it;
            }
            it++;
        }
        return *cfgs.begin();
    }

    void    insertConf(cfg::Config &conf)
    {
        cfgs.insert(conf);
    }

    void    initLisetnSocket(void)
    {
        //TO DO
    }

};

m_srvs_t  initServers(const std::string &cfg_file)
{
    logger::Log &log = logger::Log::getInst();

	std::ifstream	config_file;
    m_srvs_t    	srvs;
    cfg::Config 	conf;

	config_file.open(cfg_file.c_str());
	if(!config_file)
    {
        log(logger::ERROR, "Config file open error: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while(cfg::getNextConfig(config_file, &conf))
    {
        srvs[conf.addr.s_addr][htons(conf.port)].insertConf(conf);
    }

    m_srvs_t::iterator it = srvs.begin();
    while (it != srvs.end())
    {
        const in_addr_t &address = it->first;
        const in_port_t &port = it->second.begin()->first;
        srvs[address][port].initLisetnSocket();
        it++;
    }
	config_file.close();
    return srvs;
}

}
