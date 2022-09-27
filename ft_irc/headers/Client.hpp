/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:26:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/09/27 15:54:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>

namespace srv
{
struct Client
{
    int         conSocket;
    char        *ip;
    in_port_t   port;

    bool    operator<(const srv::Client &s) const
    {
        return (conSocket < s.conSocket);
    }
};

}
