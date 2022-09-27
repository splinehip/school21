/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:41:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/09/27 16:20:53 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <set>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/poll.h>

#include "utils.hpp"
#include "logger/Log.h"

#include "Client.hpp"

namespace srv
{
const int MAX_EVENTS = 512;
const int BUF_SIZE = 4096;

static const int PORT_MIN = 1;
static const int PORT_MAX = 65535;

class Server;

class Server
{
public:
    int                 listenSocket;
    struct sockaddr_in  sockAddr;
    const std::string   pass;
    std::set<Client>    clients;

private:
    void    setSockAddr(const std::string &ip, const std::string &port)
    {
        logger::Log &log = logger::Log::getInst();

        sockAddr.sin_family = AF_INET;
        if (inet_aton(ip.c_str(), &sockAddr.sin_addr) == false)
        {
            log(logger::ERROR,
                "Server::setAddr, invalid address: %s", ip.c_str());
            exit(EXIT_FAILURE);
        }
        in_port_t port_val = 0;
        std::istringstream s(port);
        s >> port_val;
        if (port_val < PORT_MIN || port_val > PORT_MAX)
        {
            log(logger::ERROR, "setPort: Port %s out of range %i - %i",
                port.c_str(), PORT_MIN, PORT_MAX);
            exit(EXIT_FAILURE);
        }
        sockAddr.sin_port = htons(port_val);
    }

    void    initListenSocket(void)
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
    }

    void    startListen(void)
    {
        logger::Log &log = logger::Log::getInst();

        if (bind(listenSocket, (sockaddr *)(&sockAddr), sizeof(sockAddr)))
        {
            log(logger::ERROR, "bind: %s", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (listen(listenSocket, SOMAXCONN))
        {
            log(logger::ERROR, "listen: %s", strerror(errno));
            exit(EXIT_FAILURE);
        }
        log(logger::INFO,
                "server %s:%i start listen success.", getAddrStr(), getPort());

    }

public:
    Server(const std::string &port, const std::string &_pass,
            const std::string &ip = "0.0.0.0"): pass(_pass)
    {
        setSockAddr(ip, port);
        initListenSocket();
    };

    Server(const Server &inst): pass(inst.pass)
    {
        sockAddr = inst.sockAddr;
        initListenSocket();
    };

    ~Server(void){};

    char        *getAddrStr(void) const
    {
        return (inet_ntoa(sockAddr.sin_addr));
    }

    short int   getPort(void) const
    {
        return (ntohs(sockAddr.sin_port));
    }

    bool    isPass(const std::string &pass)
    {
        return this->pass == pass;
    }

    void    run(void)
    {
        logger::Log &log = logger::Log::getInst();

        uint32_t                    idx;
        uint32_t                    setSize;
        struct pollfd               set[MAX_EVENTS];
        struct sockaddr             src_addr;
        socklen_t                   addr_len;
        Client                      client;
        std::set<Client>::iterator  it;

        startListen();

        set[0].fd = listenSocket;
        set[0].events = POLLIN;

        addr_len = sizeof(src_addr);

        while (true)
        {
            idx = 1;
            for (it = clients.begin(); it != clients.end(); it++)
            {
                if (idx >= MAX_EVENTS)
                {
                    log(logger::ERROR,
                        "idx: %i out of set size: %i", idx, MAX_EVENTS);
                    break ;
                }
                set[idx].fd = it->conSocket;
                set[idx].events = POLLIN;
                idx++;
            }
            setSize = clients.size() + 1;
            if (poll(set, setSize, -1) < 0)
            {
                log(logger::ERROR, "poll: %s", strerror(errno));
                exit(EXIT_FAILURE);
            }
            else
            {
                for (uint32_t i = 0; i < setSize; i++)
                {
                    if (i && set[i].revents & POLLIN)
                    {
                        log(logger::INFO, "Is client socket");
                        char buf[BUF_SIZE];
                        int len = recv(set[i].fd, buf, BUF_SIZE, MSG_NOSIGNAL);
                        if (len > 0)
                        {
                            send(set[i].fd, buf, len, MSG_NOSIGNAL);
                        }
                        else
                        {
                            client.conSocket = set[i].fd;
                            clients.erase(client);
                            shutdown(client.conSocket, SHUT_RDWR);
                            close(client.conSocket);
                            log(logger::INFO, "close connection");
                        }

                    }
                    else if (set[i].revents & POLLIN)
                    {
                        client.conSocket = accept(set[i].fd,
                                                    &src_addr, &addr_len);
                        if (client.conSocket < 0)
                        {
                            log(logger::ERROR, "accept: %s", strerror(errno));
                            continue ;
                        }
                        utl::sockSetNonBlock(client.conSocket);
                        client.ip = inet_ntoa(
                                        ((sockaddr_in *)(&src_addr))->sin_addr);
                        client.port = ntohs(
                                        ((sockaddr_in *)(&src_addr))->sin_port);
                        clients.insert(client);

                        log(logger::INFO,
                            "accepted connection from client %s:%i",
                            client.ip, client.port);
                    }
                }
                log(logger::DEBUG, "next hop");
            }
        }
    }
};

}
