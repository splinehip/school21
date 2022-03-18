/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:41:07 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 09:58:38 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

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
	}
	std::cout << std::endl;
	{
		FragTrap	frag("frag_pushkin");

		frag.attack("Handsome Jack");
		frag.takeDamage(6);
		frag.beRepaired(4);
		frag.takeDamage(3);
		frag.highFivesGuys();
		frag.beRepaired(8);
		frag.takeDamage(17);
	}
	std::cout << std::endl;
	{
		DiamondTrap dimond("dimond_pushkin");

		dimond.attack("Handsome Jack");
		dimond.takeDamage(6);
		dimond.beRepaired(4);
		dimond.takeDamage(3);
		dimond.guardGate();
		dimond.highFivesGuys();
		dimond.whoAmI();
		dimond.beRepaired(8);
		dimond.takeDamage(17);
	}
	return (0);
}
