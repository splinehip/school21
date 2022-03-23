/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:56 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 17:07:45 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
# define Animal_HPP
# define UINT unsigned int
# include <iostream>
# include <string>

class Animal
{
protected:
	std::string		type;

public:
	Animal();
	Animal(std::string name);
	Animal(Animal const &inst);
	virtual ~Animal();

	Animal 		&operator=(Animal const &inst);

	const std::string	&getType(void) const;
	virtual void		makeSound(void) const;
};

std::ostream			&operator<<(std::ostream &out, const Animal &inst);

#endif
