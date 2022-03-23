/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:33:48 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 10:42:18 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &inst): AMateria(inst) {}

Ice::~Ice() {}

Ice	&Ice::operator=(const Ice &inst)
{
	if (this == &inst)
		return (*this);
	AMateria::operator=(inst);
	return (*this);
}

AMateria		*Ice::clone(void) const
{
	return (new Ice(*this));
}

void			Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
	AMateria::use(target);
}
