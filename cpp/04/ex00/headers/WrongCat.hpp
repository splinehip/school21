/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:53:07 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 16:08:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
# define WrongCat_HPP
# define UINT unsigned int
# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
protected:
	std::string		name;

public:
	WrongCat();
	WrongCat(std::string name);
	WrongCat(WrongCat const &inst);
	~WrongCat();

	WrongCat 			&operator=(WrongCat const &inst);

	const std::string	&getName(void) const;
	void				makeSound(void) const;
};

std::ostream			&operator<<(std::ostream &out, const WrongCat &inst);

#endif
