/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:40:32 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 10:43:17 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure &inst): AMateria(inst) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &inst)
{
	if (this == &inst)
		return (*this);
	AMateria::operator=(inst);
	return (*this);
}

AMateria		*Cure::clone(void) const
{
	return (new Cure(*this));
}

void			Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}
