/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:36:21 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 16:08:09 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP
# define UINT unsigned int
# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog: public Animal
{
protected:
	std::string		name;

public:
	Dog();
	Dog(std::string name);
	Dog(Dog const &inst);
	~Dog();

	Dog 				&operator=(Dog const &inst);

	const std::string	&getName(void) const;
	void				makeSound(void) const;
};

std::ostream			&operator<<(std::ostream &out, const Dog &inst);

#endif
