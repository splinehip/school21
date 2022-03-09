/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:59:19 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/05 16:44:34 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	int		i;
	Zombie	*zh;

	zh = new Zombie[n];
	i = 0;
	while (i < n)
		zh[i++].setName(name);
	return (zh);
}
