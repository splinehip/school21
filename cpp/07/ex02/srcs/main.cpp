/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:09:40 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/03 19:23:42 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

int main( void )
{
	Array<int> j(5);
    Array<std::string> list(2);

	std::cout << "String array content befor init: " << std::endl;
    for (unsigned int i = 0; i < list.size(); i++)
        std::cout << "list[" << i << "] = " << list[i] << std::endl;

    list[0] = "test";
    list[1] = "plop";

	std::cout << std::endl;
    std::cout << "String array content : " << std::endl;
    for (unsigned int i = 0; i < list.size(); i++)
        std::cout << "list[" << i << "] = " << list[i] << std::endl;

    std::cout << std::endl;
    std::cout << "Copy list :" << std::endl;
    Array<std::string> listcopy(list);
    std::cout << "Change list[0] to \"murp\"" << std::endl;
    list[0] = "murp";
    std::cout << "Listcopy[0] = " << listcopy[0] << std::endl;
    std::cout << "List[0] = " << list[0] << std::endl;

    std::cout << std::endl;
    std::cout << "Int array content : " << std::endl;
    for (unsigned int i = 0; i < j.size(); i++)
        std::cout << "j" << i << " = " << j[i] << std::endl;

    std::cout << std::endl;
    Array<int> intassign = j;
    std::cout << "Int array content : " << std::endl;
    for (unsigned int i = 0; i < j.size(); i++)
        std::cout << "intassign[" << i << "] = " << intassign[i] << std::endl;

    std::cout << std::endl;
    std::cout << "Modify value (previous + 1): " << std::endl;
    for (unsigned int i = 0; i < j.size(); i++)
        if (i != 0)
            intassign[i] = intassign[i - 1] + 1;
    for (unsigned int i = 0; i < j.size(); i++)
        std::cout << "intassign[" << i << "] = " << intassign[i] << std::endl;

    std::cout << std::endl;
    std::cout << "See out of the bound i: " << j.size() + 1 << std::endl;
	try
	{
		std::cout << "jx = " << j[j.size() + 1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
