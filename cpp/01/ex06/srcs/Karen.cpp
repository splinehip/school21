/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:30:32 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/09 15:06:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Karen.hpp"

enum e_level
{
	error = 1,
	warning,
	info,
	debug
};

Karen::Karen(void){this->level = 0;}
Karen::~Karen(void){}

void Karen::debug(void)
{
	std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void Karen::info(void)
{
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon \
costs more money. You didn’t put enough bacon in my burger! If you did, I \
wouldn’t be asking for more!"
	<< std::endl;
}

void Karen::warning(void)
{
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some \
extra bacon for free. I’ve been coming for years whereas you started working \
here since last month."
	<< std::endl;
}

void Karen::error(void)
{
	std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to \
speak to the manager now."
	<< std::endl;
}

static int		getLevelID(std::string level)
{
	if (level.compare("DEBUG") == 0)
		return (debug);
	else if (level.compare("INFO") == 0)
		return (info);
	else if (level.compare("WARNING") == 0)
		return (warning);
	else if (level.compare("ERROR") == 0)
		return (error);
	return (-1);
}

void	Karen::setLevel(std::string level)
{
	this->level = getLevelID(level);
	if (this->level < 0 )
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
}

void	Karen::complain(std::string level)
{
	void	(Karen::*f)(void);

	void	(Karen::*funcs[])(void) = {
	 	&Karen::error,
		&Karen::warning,
		&Karen::info,
		&Karen::debug
	};
	std::string	levels[] = {
		"error",
		"warning",
		"info",
		"debug"
	};
	for (int i = 0; i < this->level; i++)
	{
		if (level == levels[i])
		{
			 f = funcs[i];
			(this->*f)();
		}
	}
}
