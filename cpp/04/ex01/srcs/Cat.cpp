/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:53:40 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 19:55:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain())
{
	this->name = "NoName";
	//this->brain = new Brain();
	std::cout << "Cat: default constructor called." << std::endl;
}

Cat::Cat(std::string name): Animal("Cat"), brain(new Brain())
{
	this->name = name;
	//this->brain = new Brain();
	std::cout << "Cat: Name constructor called. " << this->name << std::endl;
}

Cat::Cat(Cat const &inst): Animal("Cat")
{
	*this = inst;
	std::cout << "Cat: copy constructor called. " << this->name << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: destructor called." << std::endl;
	delete this->brain;
}

Cat	&Cat::operator=(Cat const &inst)
{
	this->name = inst.name;
	*this->brain = *inst.brain;
	std::cout << "Cat: default assignment called." << this->name << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat " << getName() << " Myau" << std::endl;
}

const std::string		&Cat::getName(void) const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &out, const Cat &inst)
{
	return (out << "Cat: " << inst.getName() << std::endl);
}

std::string	&Cat::getIdea(int i)
{
	return (this->brain->getIdea(i));
}

void	Cat::setIdea(int i, std::string value)
{
	this->brain->setIdea(i, value);
}
