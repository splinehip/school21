/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:41:07 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 17:04:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

int	main(void)
{
	{
		ClapTrap	clap("clap_pushkin");

		clap.attack("Handsome Jack");
		clap.takeDamage(6);
		clap.beRepaired(4);
		clap.takeDamage(3);
		clap.beRepaired(8);
		clap.takeDamage(17);
	}
	std::cout << std::endl;
	{
		ScavTrap	scav("scav_pushkin");

		scav.attack("Handsome Jack");
		scav.takeDamage(6);
		scav.beRepaired(4);
		scav.takeDamage(3);
		scav.guardGate();
		scav.beRepaired(8);
		scav.takeDamage(17);
		scav.takeDamage(100);
		scav.beRepaired(8);
	}
	return (0);
}
