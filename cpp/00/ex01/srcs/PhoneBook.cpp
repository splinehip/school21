/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:28:30 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/21 21:39:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
}

void	PhoneBook::add(std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	int	i;

	if (this->count < 8)
	{
		this->contacts[this->count].add(first_name, last_name, nickname,
			phone_number, darkest_secret);
		this->count++;
	}
	else
	{
		i = 0;
		while (i < this->count - 1)
		{
			this->contacts[i] = this->contacts[i + 1];
			i++;
		}
		this->contacts[i].add(first_name, last_name, nickname,
			phone_number, darkest_secret);
	}
}

void	PhoneBook::search()
{
	int	i;

	std::cout << SEARCH_HADER << std::endl;
	if (this->count == 0)
	{
		std::cout << "Phone book is empty" << std::endl;
		return ;
	}
	i = 0;
	while (i < this->count)
	{
		std::cout << "|" << std::setw(10) << i;
		if (this->contacts[i].get("first_name").length() > 10)
			std::cout << "|" << this->contacts[i].get("first_name").substr(
				0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->contacts[i].get(
				"first_name");
		if (this->contacts[i].get("last_name").length() > 10)
			std::cout << "|" << this->contacts[i].get("last_name").substr(
				0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->contacts[i].get(
				"last_name");
		if (this->contacts[i].get("nickname").length() > 10)
			std::cout << "|" << this->contacts[i].get("nickname").substr(
				0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->contacts[i].get(
				"nickname");
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << SEARCH_FOOTER << std::endl;
}

void	PhoneBook::display_contact(void)
{
	int	i;

	if (this->count == 0)
		return ;
	std::cout << "index> ";
	if (std::cin >> i)
	{
		if ( i >= this->count || i < 0)
		{
		std::cout << "Index out of range!" << std::endl;
		return ;
		}
		std::cout << std::endl;
		std::cout << "First name:	"
			<< this->contacts[i].get("first_name") << std::endl;
		std::cout << "Last name:	"
			<< this->contacts[i].get("last_name") << std::endl;
		std::cout << "Nickname:	"
			<< this->contacts[i].get("nickname") << std::endl;
		std::cout << "Phone number:	"
			<< this->contacts[i].get("phone_number") << std::endl;
		std::cout << "Darkest secret:	"
			<< this->contacts[i].get("darkest_secret") << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Invalid index value entered!" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}
