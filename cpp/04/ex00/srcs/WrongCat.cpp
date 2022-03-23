/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:53:40 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 16:08:42 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat(): name("WrongCat")
{
	this->name = "NoName";
	std::cout << "WrongCat: default constructor called." << std::endl;
}

WrongCat::WrongCat(std::string name): WrongAnimal("WrongCat")
{
	this->name = name;
	std::cout << "WrongCat: Name constructor called. " << this->name << std::endl;
}

WrongCat::WrongCat(WrongCat const &inst): WrongAnimal("WrongCat")
{
	*this = inst;
	std::cout << "WrongCat: copy constructor called. " << this->name << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor called." << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &inst)
{
	this->name = inst.name;
	std::cout << "WrongCat: default assignment called." << this->name << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat " << getName() << " Myau" << std::endl;
}

const std::string		&WrongCat::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &out, const WrongCat &inst)
{
	return (out << "WrongCat: " << inst.getName() << std::endl);
}
