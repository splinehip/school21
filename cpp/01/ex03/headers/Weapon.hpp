/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:28:32 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/07 15:34:41 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(void);
	Weapon(std::string	type);
	~Weapon(void);
	const std::string	&getType(void);
	void				setType(std::string type);
};

#endif
