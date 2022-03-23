/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:49:05 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 17:43:43 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	this->name = "NoName";
	std::cout << "Dog: default constructor called." << std::endl;
}

Dog::Dog(std::string name): Animal("Dog")
{
	this->name = name;
	std::cout << "Dog: Name constructor called. " << this->name << std::endl;
}

Dog::Dog(Dog const &inst): Animal("Dog")
{
	*this = inst;
	std::cout << "Dog: copy constructor called. " << this->name << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called." << std::endl;
}

Dog	&Dog::operator=(Dog const &inst)
{
	this->name = inst.name;
	std::cout << "Dog: default assignment called." << this->name << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog " << getName() << " Gav" << std::endl;
}

const std::string		&Dog::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &out, const Dog &inst)
{
	return (out << "Dog: " << inst.getName() << std::endl);
}
