/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:41:07 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 11:50:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap pushkin("Pushkin");

	pushkin.attack("Handsome Jack");
	pushkin.takeDamage(6);
	pushkin.beRepaired(4);
	pushkin.takeDamage(3);
	pushkin.beRepaired(8);
	pushkin.takeDamage(17);
	return (0);
}
