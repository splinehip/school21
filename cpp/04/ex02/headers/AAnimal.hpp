/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:56 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/21 14:36:29 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP
# define UINT unsigned int
# include <iostream>
# include <string>

class AAnimal
{
protected:
	std::string		type;

public:
	AAnimal(std::string type);
	virtual ~AAnimal();


	void				setType(std::string type);
	const std::string	&getType(void) const;
	virtual void		makeSound(void) const = 0;
	virtual std::string	&getIdea(int i) = 0;
	virtual void		setIdea(int i, std::string value) = 0;
};

std::ostream			&operator<<(std::ostream &out, const AAnimal &inst);

#endif
