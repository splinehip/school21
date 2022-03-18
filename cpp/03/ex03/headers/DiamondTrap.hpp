/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:40:57 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/18 10:39:33 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string	_name;

public:
	DiamondTrap(void);
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &inst);
	~DiamondTrap( void );

	DiamondTrap	&operator=(const DiamondTrap &inst);

	void	attack(const std::string &target);
	void	whoAmI(void) const;
};

#endif
