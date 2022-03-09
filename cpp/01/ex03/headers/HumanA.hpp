/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:37:04 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/07 13:23:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon		*weapon;
	std::string	name;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void	attack(void);
};

#endif
