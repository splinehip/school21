/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:56 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/17 17:07:45 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define UINT unsigned int
# include <string>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	hit;
	unsigned int	max_hit;
	unsigned int	energy;
	unsigned int	damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &inst);
	~ClapTrap();

	ClapTrap 		&operator=(ClapTrap const &inst);

	void			initAttr(UINT hit, UINT energy, UINT damage);
	void			attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	int				zeroHitPoint(void);
	int				zeroEnergy(void);
};

#endif
