/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:14:41 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 11:16:16 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual	~IMateriaSource() {};

		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
