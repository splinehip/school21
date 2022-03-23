/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:41:07 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/21 12:23:45 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <string>
#include <cassert>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static std::string	to_string( int x ) {
  int length = snprintf( NULL, 0, "%d", x );
  assert( length >= 0 );
  char* buf = new char[length + 1];
  snprintf( buf, length + 1, "%d", x );
  std::string str( buf );
  delete[] buf;
  return str;
}

int	main(void)
{
	int					i;
	Animal				*a[4];

	i = 0;
	while (i < 4)
	{
		if (i < 2)
			a[i] = new Dog(to_string(i));
		else
			a[i] = new Cat(to_string(i));
		a[i]->setIdea(0, to_string(i));
		i++;
		std::cout << std::endl;
	}
	a[0]->makeSound();
	std::cout << "a[0]: " << *a[0] << "a[0]->getIdea(0)" << a[0]->getIdea(0)
		<< std::endl;
	std::cout << "a[2]: " << *a[2] << "a[2]->getIdea(0)" << a[2]->getIdea(0)
		<< std::endl;
	*a[0] = *a[2];
	std::cout << "a[0]: " << *a[0] << "a[0]->getIdea(0)" << a[0]->getIdea(0)
		<< std::endl;
	a[2]->makeSound();
	std::cout << std::endl;
	Dog b;
	Dog c;
	b.setIdea(0, "TUTU");
	c.setIdea(0, "KUKU");
	std::cout << std::endl;
	b.makeSound();
	std::cout << "b: " << b << "b.getIdea(0)" << b.getIdea(0)
		<< std::endl;
	c.makeSound();
	std::cout << "b: " << c << "b.getIdea(0)" << c.getIdea(0)
		<< std::endl;
	b = c;
	b.makeSound();
	std::cout << "b: " << b << "b.getIdea(0)" << b.getIdea(0)
		<< std::endl;
	a[2]->makeSound();
	std::cout << std::endl;
	a[0]->makeSound();
	std::cout << std::endl;
	i = 0;
	while (i < 4)
	{
		std::cout << "delete: " << i + 1 << std::endl;
		std::cout << "a[i]->getIdea(0)" << a[i]->getIdea(0) << std::endl;
		delete a[i++];
		std::cout << std::endl;
	}
	return (0);
}
