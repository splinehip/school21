/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:38:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/09 13:59:38 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen	karen;

	if (argc != 2)
	{
		std::cout << "Argument error: ./karenFilter <level name>" << std::endl;
		return (1);
	}
	karen.setLevel(std::string(argv[1]));
	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");
	return (0);
}
