/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:22:19 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 10:35:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): type(type) {}

AMateria::AMateria(const AMateria &inst): type(inst.getType()) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &inst)
{
	if (this == &inst)
		return (*this);
	this->type = inst.getType();
	return (*this);
}

const std::string	&AMateria::getType(void) const
{
	return (this->type);
}

void				AMateria::use(ICharacter &target)
{
	(void)target;
}
