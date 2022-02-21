/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:28:25 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/21 19:32:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::add(std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string	Contact::get(std::string fild_name)
{
	if (fild_name == std::string("first_name"))
		return (this->first_name);
	if (fild_name == std::string("last_name"))
		return (this->last_name);
	if (fild_name == std::string("nickname"))
		return (this->nickname);
	if (fild_name == std::string("phone_number"))
		return (this->phone_number);
	if (fild_name == std::string("darkest_secret"))
		return (this->darkest_secret);
	return (std::string("Contact: Unknown field_name"));
}
