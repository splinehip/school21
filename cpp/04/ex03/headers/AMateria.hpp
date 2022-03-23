/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:11:17 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 12:53:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include <string>

#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string     type;

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria&);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &inst);

		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
