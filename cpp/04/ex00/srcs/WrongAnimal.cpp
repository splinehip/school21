/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:14:27 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 16:14:29 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Notype";
	std::cout << "WrongAnimal: default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal: type constructor called. " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &inst)
{
	*this = inst;
	std::cout << "WrongAnimal: copy constructor called. " << this->type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: destructor called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &inst)
{
	this->type = inst.type;
	std::cout << "WrongAnimal: default assignment called." << this->type << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal: NoSound" << std::endl;
}

const std::string		&WrongAnimal::getType(void) const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &out, const WrongAnimal &inst)
{
	return (out << inst.getType() << std::endl);
}
