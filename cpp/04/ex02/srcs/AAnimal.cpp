/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:36:30 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/21 14:36:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AAnimal.hpp"

AAnimal::AAnimal(std::string type)
{
	this->setType(type);
	std::cout << "AAnimal: constructor called." << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: destructor called." << std::endl;
}

void		AAnimal::setType(std::string type)
{
	this->type = type;
}

const std::string		&AAnimal::getType(void) const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &out, const AAnimal &inst)
{
	return (out << inst.getType() << std::endl);
}
