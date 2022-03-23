/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:56:52 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 12:59:41 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &_name): name(_name)
{
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

Character::Character(const Character &inst)
{
	this->name = inst.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i])
			delete this->inv[i];
		if (inst.inv[i])
			this->inv[i] = inst.inv[i]->clone();
		else
			this->inv[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->inv[i])
			delete this->inv[i];
}

Character &Character::operator=(const Character &inst)
{
	if (this == &inst)
		return (*this);
	this->name = inst.getName();
	for (int i = 0; i < 4; i++)
	{
		if (inst.inv[i])
			this->inv[i] = inst.inv[i];
		else
			this->inv[i] = NULL;
	}

	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->name);
}

void				Character::equip(AMateria *m)
{
	int i = 0;

	for (i = 0; i < 4 && this->inv[i]; i++);

	if (i < 4)
		this->inv[i] = m;
}

void				Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inv[idx] = NULL;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->inv[idx])
		this->inv[idx]->use(target);
}
