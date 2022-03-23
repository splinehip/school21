/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:49:05 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/21 14:27:41 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog")
{
	this->name = "NoName";
	this->brain = new Brain();
	std::cout << "Dog: default constructor called." << std::endl;
}

Dog::Dog(std::string name): AAnimal("Dog")
{
	this->name = name;
	this->brain = new Brain();
	std::cout << "Dog: Name constructor called. " << this->name << std::endl;
}

Dog::Dog(Dog const &inst): AAnimal("Dog")
{
	*this = inst;
	std::cout << "Dog: copy constructor called. " << this->name << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called." << std::endl;
	delete this->brain;
}

Dog	&Dog::operator=(Dog const &inst)
{
	this->name = inst.name;
	*this->brain = *inst.brain;
	std::cout << "Dog: default assignment called." << this->name << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << " " << getName() << " Gav" << std::endl;
}

const std::string		&Dog::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &out, const Dog &inst)
{
	return (out << "Dog: " << inst.getName() << std::endl);
}

std::string	&Dog::getIdea(int i)
{
	return (this->brain->getIdea(i));
}

void	Dog::setIdea(int i, std::string value)
{
	this->brain->setIdea(i, value);
}
