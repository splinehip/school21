/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggerUtils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:27:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/12 14:07:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LOGGERUTILS_HPP
# define LOGGERUTILS_HPP
# include "Logger/Logger.hpp"

inline std::string	time_stamp(void)
{
	std::ostringstream	strtime;
	std::time_t			t;
	tm					stamp;

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

void				*serializer(void *_this);

#endif
