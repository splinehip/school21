/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:38:47 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 10:50:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure&);
		virtual	~Cure();
		Cure &operator=(const Cure &inst);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
