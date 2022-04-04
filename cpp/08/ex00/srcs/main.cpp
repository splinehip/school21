/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:09:40 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/04 13:06:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "easyfind.hpp"

static void	print(int i)
{
	std::cout << i << " ";
}

int main( void ) {
	std::vector<int>	a;

	for(int i = 10; i < 50; i += 10)
		a.push_back(i);
	std::cout << "array: ";
	std::for_each(a.begin(), a.end(), print);
	std::cout << std::endl;
	if (easyfind(a, 30) >= 0)
		std::cout << "30 found in a[" << easyfind(a, 30) << "]" << std::endl;
	else
		std::cout << "30 not found" << std::endl;
	if (easyfind(a, 50) >= 0)
		std::cout << "50 found in a[" << easyfind(a, 30) << "]" << std::endl;
	else
		std::cout << "50 not found" << std::endl;
	return 0;
}
