/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:39:51 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/05 15:13:58 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
	void	randomChump(std::string name);
};

Zombie*	newZombie(std::string name);

#endif
