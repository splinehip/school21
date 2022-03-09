/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:11:37 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/05 16:38:55 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

int main(void)
{
	int		i;
	Zombie	*zh;

	zh = zombieHorde(10, "BAZZZ");
	i = 0;
	while (i < 10)
	{
		std::cout << "zombie[" << i << "] ";
		zh[i++].announce();
	}
	delete[] zh;
	return (0);
}
