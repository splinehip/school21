/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggerUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:23:58 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/13 21:54:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger/loggerUtils.hpp"

void	*serializer(void *_this)
{
	logger::Log	*log;
	std::string	msg;

	log = reinterpret_cast<logger::Log *>(_this);
	while (log->stop() == false)
	{
		log->nextMsg(msg);
		if (msg.empty() == false)
		{
			if (log->getLevel() > WARNING)
			{
				std::cerr << msg << std::endl;
			}
			else
			{
				std::cout << msg << std::endl;
			}
			log->serialize(msg);
		}
		else
		{
			usleep(900);
		}
	}
	exit(EXIT_SUCCESS);
}
