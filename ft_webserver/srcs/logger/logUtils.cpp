/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:23:58 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/21 16:28:02 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/logger/logUtils.h"

std::string time_stamp(void)
{
    std::ostringstream  strtime;
    std::time_t         t;
    tm                  stamp;

    t = time(NULL);
    stamp = *localtime(&t);
    strtime << std::setfill('0') << "["
            << (stamp.tm_year + 1900) << "."
            << std::setw(2) << stamp.tm_mon + 1 << "."
            << std::setw(2) << stamp.tm_mday << "_"
            << std::setw(2) << stamp.tm_hour << ":"
            << std::setw(2) << stamp.tm_min << ":"
            << std::setw(2) << stamp.tm_sec << "] ";
    return(strtime.str());
}

void    *serializer(void *this_)
{
    logger::Log	*log;

    log = reinterpret_cast<logger::Log *>(this_);
    log->do_serialize();
    return (EXIT_SUCCESS);
}
