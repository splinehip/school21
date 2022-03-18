/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:36:30 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 17:18:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "No name";
	initAttr(10, 10, 0);
	std::cout << "Default constructor called: " << this->name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	initAttr(10, 10, 0);
	std::cout << "Name constructor called: " << this->name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &inst)
{
	*this = inst;
	std::cout << "Default copy constructor called: " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called, for ClapTrap" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &inst)
{
	this->name = inst.name;
	this->energy = inst.energy;
	this->damage = inst.damage;
	std::cout << "Default assignment called: " << this->name << std::endl;
	return (*this);
}

void	ClapTrap::initAttr(UINT hit, UINT energy, UINT damage)
{
	this->hit = hit;
	this->max_hit = hit;
	this->energy = energy;
	this->damage = damage;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->zeroHitPoint())
		return;
	if (this->energy == 0)
	{
		std::cout << "ClapTrap " << this->name << " 0 energy point, can`t attack." << std::endl;
		return;
	}
	this->energy--;
	std::cout << "ClapTrap " << this->name << " attacks " << target
			<< ", causing " << this->damage << " points of damage!" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->zeroHitPoint() || this->zeroEnergy())
		return;
	std::cout << "ClapTrap " << this->name << " take " << amount
		<< " points of damage!";
	while (amount-- && this->energy && this->hit)
	{
		this->hit--;
		this->damage++;
		this->energy--;
	}
	std::cout << " Hit point now " << this->hit << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->zeroHitPoint() || this->zeroEnergy())
		return;
	std::cout << "ClapTrap " << this->name << " take " << amount
		<< " points of repaire!";
	while (amount-- && this->energy && this->hit != this->max_hit)
	{
		this->hit++;
		this->energy--;
	}
	std::cout << " Hit point now " << this->hit << std::endl;
}

int		ClapTrap::zeroHitPoint(void)
{
	if (this->hit == 0)
	{
		std::cout << "ClapTrap " << this->name
			<< " 0 hit point, can`t do any thing." << std::endl;
		return (true);
	}
	return (false);
}

int		ClapTrap::zeroEnergy(void)
{
	if (this->energy == 0)
	{
		std::cout << "ClapTrap " << this->name
			<< " 0 energy, can`t do any thing." << std::endl;
		return (true);
	}
	return (false);
}
