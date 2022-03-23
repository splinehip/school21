/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:16:20 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 19:47:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
protected:
	std::string		ideas[100];

public:
	Brain();
	Brain(Brain const &inst);
	virtual ~Brain();

	Brain 		&operator=(Brain const &inst);
	std::string	&getIdea(int i);
	void		setIdea(int i, std::string &value);
};

#endif
