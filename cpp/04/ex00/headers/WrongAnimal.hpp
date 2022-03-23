/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:13:36 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 16:13:38 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP
# define UINT unsigned int
# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string		type;

public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(WrongAnimal const &inst);
	virtual ~WrongAnimal();

	WrongAnimal 		&operator=(WrongAnimal const &inst);

	const std::string	&getType(void) const;
	void				makeSound(void) const;
};

std::ostream			&operator<<(std::ostream &out, const WrongAnimal &inst);

#endif
