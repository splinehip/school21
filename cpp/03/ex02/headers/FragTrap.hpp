/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:34:20 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 16:35:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
private:

public:
	FragTrap(void);
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &inst);
	~FragTrap(void);

	FragTrap	&operator=(const FragTrap &inst);

	void		highFivesGuys(void);
};

#endif
