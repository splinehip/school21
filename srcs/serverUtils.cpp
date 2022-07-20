/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:39:41 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/17 12:08:14 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.h"

in_addr_t    srv::aton(std::string cp)
{
    struct  in_addr addr;

    logger::Log &log = logger::Log::getInst();
    if (inet_aton(cp.c_str(), &addr))
        return (addr.s_addr);
    log(logger::ERROR, "Invalid address convertion, %s to in_addr.", cp);
    return (0);
}

char    *srv::ntoa(in_addr_t in_addr)
{
    struct  in_addr addr;

    addr.s_addr = in_addr;
    return (inet_ntoa(addr));
}
