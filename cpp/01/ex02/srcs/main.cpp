/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:01:42 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/07 11:19:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string	str;
	std::string	*pstr;

	str = "HI THIS IS BRAIN";
	pstr = &str;
	std::string &rstr = str;
	std::cout << "addr  str: " << &str << " value: " << str << std::endl;
	std::cout << "addr pstr: " << &pstr << " value: " << *pstr << std::endl;
	std::cout << "addr rstr: " << &rstr << " value: " << rstr << std::endl;
	return (0);
}
