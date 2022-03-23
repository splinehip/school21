/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:53:07 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 19:55:45 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP
# define UINT unsigned int
# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain			*brain;

protected:
	std::string		name;

public:
	Cat();
	Cat(std::string name);
	Cat(Cat const &inst);
	~Cat();

	Cat 				&operator=(Cat const &inst);

	const std::string	&getName(void) const;
	void				makeSound(void) const;
	std::string			&getIdea(int i);
	void				setIdea(int i, std::string value);
};

std::ostream			&operator<<(std::ostream &out, const Cat &inst);

#endif
