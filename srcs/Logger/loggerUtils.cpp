/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggerUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:23:58 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/13 22:43:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger/loggerUtils.hpp"

void	*serializer(void *_this)
{
	logger::Log	*log;

	log = reinterpret_cast<logger::Log *>(_this);
	log->serialize();
	exit(EXIT_SUCCESS);
}
