/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:41:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/09/18 16:37:31 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <set>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#include "Config.hpp"
#include "logger/Log.h"

namespace srv
{
const int MAX_EVENTS = SOMAXCONN;

class Server;

typedef std::map<struct sockaddr_in, srv::Server, utl::lessAddr>    m_srvs_t;
typedef std::set<cfg::Config, cfg::lessCfg>                         cfgs_t;

class Server
{
public:
    int                 listenSocket;
    struct sockaddr_in  sockAddr;
    struct epoll_event  event;
    cfgs_t              cfgs;

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

    void        insertConf(cfg::Config &conf)
    {
        cfgs.insert(conf);
    }

    void        initListenSocket(void)
    {
        logger::Log &log = logger::Log::getInst();

        listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (listenSocket < 0)
        {
            log(logger::ERROR,
                "initListenSocket: socket create failed: %s", strerror(errno));
            exit(EXIT_FAILURE);
        }
        utl::sockSetReuseAddr(listenSocket);
        utl::sockSetNonBlock(listenSocket);

        event.data.fd = listenSocket;
        event.events = EPOLLIN;
    }

    char        *getAddrStr(void) const
    {
        return (inet_ntoa(sockAddr.sin_addr));
    }

    short int   getPort(void) const
    {
        return (ntohs(sockAddr.sin_port));
    }

};

const m_srvs_t  initServers(const std::string &cfg_file)
{
    logger::Log &log = logger::Log::getInst();

	std::ifstream       config_file;
    m_srvs_t            srvs;
    cfg::Config         conf;
    struct sockaddr_in  addr;

	config_file.open(cfg_file.c_str());
	if(!config_file)
    {
        log(logger::ERROR, "initServers: Config file open error: %s",
            strerror(errno));
        exit(EXIT_FAILURE);
    }

    while(cfg::getNextConfig(config_file, conf, addr))
    {
        srv::m_srvs_t::iterator it = srvs.find(addr);
        if (it == srvs.end())
        {
            Server &s = srvs[addr];
            s.insertConf(conf);
            s.sockAddr.sin_family = AF_INET;
            s.sockAddr.sin_addr = addr.sin_addr;
            s.sockAddr.sin_port = addr.sin_port;
            s.initListenSocket();
        }
        else
        {
            it->second.insertConf(conf);
        }
    }

	config_file.close();
    return srvs;
}

}
