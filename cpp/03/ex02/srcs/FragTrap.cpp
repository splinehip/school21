/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:35:58 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 17:29:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Defualt constructor for FragTrap called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	this->name = name;
	this->initAttr(100, 100, 30);
	std::cout << "Name constructor for FragTrap called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called, for FragTrap" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &inst)
{
	*this = inst;
	std::cout << "Assignement operator called" << std::endl;
	return *this;
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap highFivesGuys!" << std::endl;
}


