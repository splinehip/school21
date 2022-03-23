/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:32:03 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 10:51:17 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice&);
		virtual	~Ice();
		Ice &operator=(const Ice &inst);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
