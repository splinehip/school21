/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:09:40 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/03 17:05:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

int main( void )
{
	int a[3] = {1, 2, 3};
	unsigned int size = 3;
	std::string strs[] = { "Salut", "Comment" , "Tutu", "Vasil", "?"};

	iter(a, size, print);
	iter(strs, strs->length(), print);
	return 0;
}
