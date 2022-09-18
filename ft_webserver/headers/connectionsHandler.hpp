/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connectionsHandler.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:59:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/09/18 15:50:09 by cflorind         ###   ########.fr       */
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

bool    isListenSocket(int socket, const srv::m_srvs_t &srvs)
{
    sockaddr_in     *addr;
    struct sockaddr sock_addr;
    socklen_t       addrlen = sizeof(addr);

    getsockname(socket, &sock_addr, &addrlen);
    addr = (sockaddr_in *)(&sock_addr);
    if (srvs.find(*addr) == srvs.end())
        return false;
    return true;
}

void    run(const std::string &configFile)
{
    logger::Log &log = logger::Log::getInst();

    int             EPoll;
    int             conSocket;
    conargs_t       conargs;
    pthread_t       thread;
    sockaddr_in     *addr;
    struct sockaddr srv_addr;
    struct sockaddr src_addr;
    socklen_t       addrlen;

    addrlen = sizeof(addr);

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

    while (true)
    {
        struct epoll_event Events[srv::MAX_EVENTS];
        int N = epoll_wait(EPoll, Events, srv::MAX_EVENTS, -1);

        for (int i = 0; i < N; i++)
        {
            if (isListenSocket(Events[i].data.fd, srvs))
            {
                conSocket = accept(Events[i].data.fd, &src_addr, &addrlen);
                utl::sockSetNonBlock(conSocket);
                struct epoll_event event;
                event.data.fd = conSocket;
                event.events = EPOLLIN;
                epoll_ctl(EPoll, EPOLL_CTL_ADD, conSocket, &event);


                conargs.conSocket = conSocket;

                addr = (sockaddr_in *)(&src_addr);
                conargs.client_ip = inet_ntoa(addr->sin_addr);
                conargs.client_port = ntohs(addr->sin_port);

                getsockname(conSocket, &srv_addr, &addrlen);
                addr = (sockaddr_in *)(&srv_addr);

                log(logger::DEBUG, "Accept new connection from: %s:%i, to: %s:%i",
                        conargs.client_ip, conargs.client_port,
                        inet_ntoa(addr->sin_addr), ntohs(addr->sin_port));

                conargs.srv = &srvs[*addr];

                pthread_create(&thread, NULL, &requestHandler, (void *)(&conargs));
            }
        }
    }
}

}
