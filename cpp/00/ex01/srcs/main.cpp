/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:56:02 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/21 21:32:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	PhoneBook	book;

	std::cout << "Phone book" << std::endl;
	std::cout << "Available command: ADD, SEARCH, EXIT" << std::endl;
	while (true)
	{
		std::cout << "> ";
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			std::cout << "First name: ";
			std::cin >> first_name;
			std::cout << "Last name: ";
			std::cin >> last_name;
			std::cout << "Nick name: ";
			std::cin >> nickname;
			std::cout << "Phone number: ";
			std::cin >> phone_number;
			std::cout << "Darkest secret: ";
			std::cin >> darkest_secret;
			book.add(first_name, last_name, nickname, phone_number,
					darkest_secret);
		}
		else if (cmd == "SEARCH")
		{
			book.search();
			book.display_contact();
		}
		else if (cmd == "EXIT")
			exit(0);
		else
		{
			std::cout << "Undefined command: " << cmd << std::endl;
			std::cout << "Available command: ADD, SEARCH, EXIT" << std::endl;
		}
	}
}
