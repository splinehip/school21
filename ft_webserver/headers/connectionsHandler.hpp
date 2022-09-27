/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connectionsHandler.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:59:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/09/20 16:11:13 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "requestHandler.hpp"

namespace srv
{

void    bindSockets(const srv::m_srvs_t &srvs)
{
    logger::Log &log = logger::Log::getInst();

    srv::m_srvs_t::const_iterator it = srvs.begin();
    while (it != srvs.end())
    {
        const srv::Server &srv = it->second;
        if (bind(srv.listenSocket, (struct sockaddr *)(&srv.sockAddr),
                sizeof(srv.sockAddr)))
        {
            log(logger::ERROR, "bindSockets: socket %s:%i bind error: %s",
                srv.getAddrStr(), srv.getPort(), strerror(errno));
            exit(EXIT_FAILURE);
        }
        log(logger::DEBUG, "bindSockets: success binded %s:%i",
            srv.getAddrStr(), srv.getPort());
        it++;
    }
}

void    startListen(const srv::m_srvs_t &srvs)
{
    logger::Log &log = logger::Log::getInst();

    srv::m_srvs_t::const_iterator it = srvs.begin();

    while (it != srvs.end())
    {
        const srv::Server &srv = it->second;
        if (listen(srv.listenSocket, SOMAXCONN))
        {
            log(logger::ERROR, "startListen: start listen %s:%i error: %s",
                srv.getAddrStr(), srv.getPort(), strerror(errno));
            exit(EXIT_FAILURE);
        }
        else
        {
            log(logger::DEBUG,
                "startListen: server success start listen at %s:%i",
                    srv.getAddrStr(), srv.getPort());
        }
        it++;
    }
}

void    addPoll(int EPoll, srv::m_srvs_t &srvs)
{
    logger::Log &log = logger::Log::getInst();

    srv::m_srvs_t::iterator it = srvs.begin();
    while (it != srvs.end())
    {
        srv::Server &srv = it->second;
        if (epoll_ctl(EPoll, EPOLL_CTL_ADD, srv.listenSocket, &srv.event))
        {
            log(logger::ERROR, "addPoll: add to poll %s:%i error: %s",
                srv.getAddrStr(), srv.getPort(), strerror(errno));
            exit(EXIT_FAILURE);
        }
        else
        {
            log(logger::DEBUG, "addPoll: server %s:%i success added",
                srv.getAddrStr(), srv.getPort());
        }
        it++;
    }
}

bool    isListenSocket(int socket, const std::set<int> &consockets,
                        const srv::m_srvs_t &srvs, conargs_t &conargs)
{
    logger::Log &log = logger::Log::getInst();

    srv::m_srvs_t::const_iterator   it;
    sockaddr_in                     *addr;
    struct sockaddr                 sock_addr;
    socklen_t                       addrlen = sizeof(addr);

    if (consockets.find(socket) != consockets.end())
    {
        log(logger::DEBUG, "isListenSocket: this is connection socket %i", socket);
        return false;
    }

    if (getsockname(socket, &sock_addr, &addrlen))
    {
        log(logger::DEBUG, "isListenSocket: getsockname error: %s",
            strerror(errno));
        return false;
    }
    addr = (sockaddr_in *)(&sock_addr);

    it = srvs.find(*addr);

    if (it == srvs.end())
    {
        log(logger::DEBUG, "isListenSocket: server %s:%i not found.",
            inet_ntoa(addr->sin_addr), addr->sin_port);
        return false;
    }
    else
    {
        conargs.srv = &it->second;
        log(logger::DEBUG, "isListenSocket: server %s:%i found",
            conargs.srv->getAddrStr(), conargs.srv->getPort());
        return true;
    }
}

void    run(const std::string &configFile)
{
    logger::Log &log = logger::Log::getInst();

    int                 EPoll;
    struct epoll_event  Events[srv::MAX_EVENTS];
    conargs_t           conargs;
    pthread_t           thread;
    struct sockaddr     src_addr;
    socklen_t           addrlen;
    std::set<int>       consockets;

    addrlen = sizeof(sockaddr);

    srv::m_srvs_t srvs = srv::initServers(configFile);

    bindSockets(srvs);
    startListen(srvs);

    EPoll = epoll_create1(0);
    if (EPoll < 0)
    {
        log(logger::ERROR, "run: EPoll create error: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    addPoll(EPoll, srvs);

    conargs.EPoll = EPoll;

    while (true)
    {
        int N = epoll_wait(EPoll, Events, srv::MAX_EVENTS, -1);
        log(logger::DEBUG, "run: new %i events hapend", N);
        for (int i = 0; i < N; i++)
        {
            if (isListenSocket(Events[i].data.fd, consockets, srvs, conargs))
            {
                conargs.conSocket = accept(Events[i].data.fd, &src_addr, &addrlen);
                if (conargs.conSocket < 0 && errno == EAGAIN)
                {
                    log(logger::DEBUG, "run: accept return EAGAIN");
                    continue ;
                }
                utl::sockSetNonBlock(conargs.conSocket);

                conargs.client_ip = inet_ntoa(((sockaddr_in *)(&src_addr))->sin_addr);
                conargs.client_port = ntohs(((sockaddr_in *)(&src_addr))->sin_port);

                log(logger::DEBUG,
                    "server %s:%i: accept new connection from: %s:%i",
                    conargs.srv->getAddrStr(), conargs.srv->getPort(),
                    conargs.client_ip, conargs.client_port);
                consockets.insert(conargs.conSocket);
                pthread_create(&thread, NULL, &requestHandler, (void *)(&conargs));
            }
        }
    }
}

}
