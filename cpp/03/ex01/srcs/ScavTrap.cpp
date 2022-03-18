/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:40:54 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 17:27:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Defualt constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	this->name = name;
	this->initAttr(100, 50, 20);
	std::cout << "Name constructor for ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called, for ScavTrap" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &inst)
{
	*this = inst;
	std::cout << "Assignement operator called" << std::endl;
	return *this;
}

void		ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " entered Gate Keeper mode!"
		<< std::endl;
}

void		ScavTrap::attack(std::string const &target)
{
	if (this->zeroHitPoint() || this->zeroEnergy())
		return;
	this->damage++;
	std::cout << "FragTrap " << this->name << " attack " << target
		<< " causing " << this->damage << " points of damage!" << std::endl;
}
