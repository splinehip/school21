/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:39:51 by cflorind          #+#    #+#             */
/*   Updated: 2022/03/05 16:40:09 by cflorind         ###   ########.fr       */
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
	void	setName(std::string name);
	void	announce(void);
	~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif
