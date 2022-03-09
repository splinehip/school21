/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:30:32 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/09 12:18:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Karen.hpp"

Karen::Karen(void){}
Karen::~Karen(void){}

void Karen::debug(void)
{
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking \
for more!"
	<< std::endl;
}

void Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month."
	<< std::endl;
}

void Karen::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void	Karen::complain(std::string level)
{
	void	(Karen::*f)(void);

	void	(Karen::*funcs[])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
	 	&Karen::error
	};
	std::string	levels[] = {
		"debug",
		"info",
		"warning",
		"error"
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			 f = funcs[i];
			(this->*f)();
		}
	}
}
