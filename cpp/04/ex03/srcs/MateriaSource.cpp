/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:28:52 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 12:35:52 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &inst)
{
	for (int i = 0; i < 4; i++)
	{
		if (inst.templates[i])
			this->templates[i] = inst.templates[i];
		else
			this->templates[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->templates[i])
			delete this->templates[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &inst)
{
	if (this == &inst)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (inst.templates[i])
			this->templates[i] = inst.templates[i];
		else
			this->templates[i] = NULL;
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	for (i = 0; i < 4 && this->templates[i]; i++);

	if (i < 4)
		this->templates[i] = m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (this->templates[i] && this->templates[i]->getType() == type)
				return (this->templates[i]->clone());
	return (NULL);
}
