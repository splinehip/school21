/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:53:33 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/01 12:59:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base	*generate(void)
{
	srand(time(NULL));
	int	i = rand() % 3;

	if (i == 0){return (new A);}
	else if (i == 1){return (new B);}
	else {return (new C);}
}

void identify(Base *ptr)
{
	std::cout << "Created class is ";
	if (dynamic_cast<A*>(ptr)){std::cout << "A-type" << std::endl;}
	else if (dynamic_cast<B*>(ptr)){std::cout << "B-type" << std::endl;}
	else {std::cout << "C-type" << std::endl;}
}

void identify(Base &ref)
{
	std::cout << "Created class is ";
	try
	{
		(void)dynamic_cast<A&>(ref);
		std::cout << "A-type" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B&>(ref);
			std::cout << "B-type" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "C-type" << std::endl;
}	}	}
