/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:31:27 by cflorind          #+#    #+#             */
/*   Updated: 2022/09/18 12:50:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

namespace srv
{
struct conargs_t
{
    int                 conSocket;
    const srv::Server   *srv;
    char                *client_ip;
    int                 client_port;
};

void    *requestHandler(void *_conargs)
{
    conargs_t conargs = *((struct conargs_t *)_conargs);

    logger::Log &log = logger::Log::getInst();

    char buf[] = {0, 0, 0, 0, 0};
    int res;
    while ((res = recv(conargs.conSocket, buf, 4, MSG_NOSIGNAL)))
    {
        if (res > 0)
        {
            log(logger::INFO, "client: %s:%i, res: %i: sock: %i receive msg: %s",
                conargs.client_ip, conargs.client_port, res, conargs.conSocket, buf);
            send(conargs.conSocket, buf, 4, MSG_NOSIGNAL);
            send(conargs.conSocket, "\n", 1, MSG_NOSIGNAL);
            log(logger::INFO, "send msg to client: %s:%i: %s",
                conargs.client_ip, conargs.client_port, buf);
            if (strcmp(buf, "exit") == 0)
                break ;
            memset(buf, 0, 4);
        }
    }
    shutdown(conargs.conSocket, SHUT_RDWR);
    close(conargs.conSocket);
    log(logger::INFO, "close connection for client %s:%i",
        conargs.client_ip, conargs.client_port);
    return(EXIT_SUCCESS);
}

}
