/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:51:29 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/07 13:30:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	Weapon		*weapon;
	std::string	name;
public:
	HumanB(std::string name);
	~HumanB(void);
	void	setWeapon(Weapon &weapon);
	void	attack(void);
};

#endif
