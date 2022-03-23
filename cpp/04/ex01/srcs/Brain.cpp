/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:36:30 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 17:18:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: default constructor called." << std::endl;
}

Brain::Brain(Brain const &inst)
{
	*this = inst;
	std::cout << "Brain: copy constructor called. " << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: destructor called." << std::endl;
}

Brain	&Brain::operator=(Brain const &inst)
{
	std::copy(inst.ideas, inst.ideas + 100, this->ideas);
	std::cout << "Brain: default assignment called." << std::endl;
	return (*this);
}

std::string	&Brain::getIdea(int i)
{
	return (this->ideas[i]);
}

void	Brain::setIdea(int i, std::string &value)
{
	this->ideas[i] = value;
}
