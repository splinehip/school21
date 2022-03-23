/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:41:07 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 16:20:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog("Puf");
	const Animal* i = new Cat("Murzik");
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wj = new WrongCat("WrongMurzil");
	std::cout << std::endl;
	std::cout << wj->getType() << " " << std::endl;
	std::cout << wmeta->getType() << " " << std::endl;
	std::cout << std::endl;
	wj->makeSound();
	wmeta->makeSound();
	std::cout << std::endl;
	delete wmeta;
	std::cout << std::endl;
	delete wj;
	return (0);
}
