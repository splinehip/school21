/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:48:17 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 10:45:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default constructor for DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
{
	this->name = name + "_clap_name";
	this->_name = name;
	this->initAttr(FragTrap::hit, ScavTrap::energy, FragTrap::damage);
	std::cout << "Name constructor for DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &inst):
	ClapTrap(inst.name), FragTrap(inst.name), ScavTrap(inst.name)
{
	std::cout << "Copy constructor for DiamondTrap called" << std::endl;
	*this = inst;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor for DiamondTrap called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &inst)
{
	std::cout << "Assignement operator called" << std::endl;
	*this = inst;
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void		DiamondTrap::whoAmI(void) const
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is "
		<< this->name << std::endl;
}
