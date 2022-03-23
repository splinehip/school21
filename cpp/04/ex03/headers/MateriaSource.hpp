/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:14:03 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/23 11:18:17 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*templates[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		virtual	~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &inst);

		void		learnMateria(AMateria*);
		AMateria	*createMateria(std::string const &type);
};

#endif
