/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:36:30 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 17:18:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Notype";
	std::cout << "Animal: default constructor called." << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal: type constructor called. " << this->type << std::endl;
}

Animal::Animal(Animal const &inst)
{
	*this = inst;
	std::cout << "Animal: copy constructor called. " << this->type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: destructor called." << std::endl;
}

Animal	&Animal::operator=(Animal const &inst)
{
	this->type = inst.type;
	std::cout << "Animal: default assignment called. " << this->type << std::endl;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal: NoSound" << std::endl;
}

const std::string		&Animal::getType(void) const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &out, const Animal &inst)
{
	return (out << inst.getType() << std::endl);
}

std::string		&Animal::getIdea(int i)
{
	std::string *res;

	(void)i;
	res = new std::string("No idea");
	std::string &rres = *res;
	return (rres);
}

void	Animal::setIdea(int i, std::string value)
{
	(void)i;
	(void)value;
	return;
}
