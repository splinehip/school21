/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:31:27 by cflorind          #+#    #+#             */
/*   Updated: 2022/09/20 15:37:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

namespace srv
{
struct conargs_t
{
    int                 EPoll;
    int                 conSocket;
    struct epoll_event  event;
    const srv::Server   *srv;
    char                *client_ip;
    int                 client_port;
};

void    *requestHandler(void *_conargs)
{
    conargs_t conargs = *((struct conargs_t *)_conargs);

    logger::Log &log = logger::Log::getInst();

    conargs.event.data.fd = conargs.conSocket;
    conargs.event.events = EPOLLIN;
    epoll_ctl(conargs.EPoll, EPOLL_CTL_ADD, conargs.conSocket, &conargs.event);

    char buf[1024];
    memset(buf, 0, 1024);
    int res;
    while (true)
    {
        struct epoll_event Ev;
        int N = epoll_wait(conargs.EPoll, &Ev, 1, -1);
        log(logger::DEBUG, "server: %s:%i: client %s:%i requestHandler: events \
number: %i",
            conargs.srv->getAddrStr(), conargs.srv->getPort(),
            conargs.client_ip, conargs.client_port, N);
        if (Ev.data.fd == conargs.conSocket)
        {
            res = recv(conargs.conSocket, buf, 1024, MSG_NOSIGNAL);
            if (res == 0 && errno != EAGAIN)
            {
                log(logger::INFO,
                    "server %s:%i: close connection for client %s:%i",
                    conargs.srv->getAddrStr(), conargs.srv->getPort(),
                    conargs.client_ip, conargs.client_port);
                if (epoll_ctl(conargs.EPoll, EPOLL_CTL_DEL, Ev.data.fd, &Ev))
                {
                    log(logger::ERROR, "server %s:%i: close connection for \
client %s:%i, epoll_ctl error: %s", conargs.srv->getAddrStr(),
                                    conargs.srv->getPort(), conargs.client_ip,
                                    conargs.client_port, strerror(errno));
                }
                if (shutdown(conargs.conSocket, SHUT_RDWR) < 0)
                {
                    log(logger::ERROR, "server %s:%i: close connection for \
client %s:%i, shutdown error: %s", conargs.srv->getAddrStr(),
                                conargs.srv->getPort(), conargs.client_ip,
                                conargs.client_port, strerror(errno));
                }
                if (close(conargs.conSocket) < 0)
                {
                    log(logger::ERROR, "server %s:%i: close connection for \
client %s:%i, close error: %s", conargs.srv->getAddrStr(),
                                conargs.srv->getPort(), conargs.client_ip,
                                conargs.client_port, strerror(errno));
                }
                return (0);
            }
            else if (res > 0)
            {
                log(logger::INFO, "server %s:%i: client: %s:%i, res: %i: \
sock: %i receive msg:\n%s", conargs.srv->getAddrStr(), conargs.srv->getPort(),
                        conargs.client_ip, conargs.client_port, res,
                        conargs.conSocket, buf);
                if (strcmp(buf, "exit\r\n") == 0)
                {
                    log(logger::INFO,
                        "server %s:%i: close connection for client %s:%i",
                        conargs.srv->getAddrStr(), conargs.srv->getPort(),
                        conargs.client_ip, conargs.client_port);
                    if (epoll_ctl(conargs.EPoll, EPOLL_CTL_DEL, Ev.data.fd, &Ev))
                    {
                        log(logger::ERROR, "server %s:%i: close connection for \
client %s:%i, epoll_ctl error: %s", conargs.srv->getAddrStr(),
                                    conargs.srv->getPort(), conargs.client_ip,
                                    conargs.client_port, strerror(errno));
                    }
                    if (shutdown(conargs.conSocket, SHUT_RDWR) < 0)
                    {
                        log(logger::ERROR, "server %s:%i: close connection for \
client %s:%i, shutdown error: %s", conargs.srv->getAddrStr(),
                                    conargs.srv->getPort(), conargs.client_ip,
                                    conargs.client_port, strerror(errno));
                    }
                    if (close(conargs.conSocket) < 0)
                    {
                        log(logger::ERROR, "server %s:%i: close connection for \
client %s:%i, close error: %s", conargs.srv->getAddrStr(),
                                    conargs.srv->getPort(), conargs.client_ip,
                                    conargs.client_port, strerror(errno));
                    }

                    return (0);
                }
                send(conargs.conSocket, buf, res, MSG_NOSIGNAL);
                log(logger::INFO,
                    "server %s:%i: send msg to client: %s:%i: %s",
                    conargs.srv->getAddrStr(), conargs.srv->getPort(),
                    conargs.client_ip, conargs.client_port, buf);
                memset(buf, 0, 1024);
            }
        }
        else if (Ev.data.fd < 0)
        {
            log(logger::ERROR, "server %s:%i: lost connection for \
client %s:%i, close thread", conargs.srv->getAddrStr(),
                                conargs.srv->getPort(), conargs.client_ip,
                                conargs.client_port);
                return (0);
        }
    }
}

}
