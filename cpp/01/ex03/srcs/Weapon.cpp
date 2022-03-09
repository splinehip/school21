/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:32:41 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/07 15:35:01 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	Weapon::setType("Undefined");
}

Weapon::Weapon(std::string type)
{
	Weapon::setType(type);
}

Weapon::~Weapon()
{
	std::cout << this->getType() << ": destroyed" << std::endl;
}

const std::string	&Weapon::getType(void)
{
	return (this->type);
}
void	Weapon::setType(std::string type)
{
	this->type = type;
}
