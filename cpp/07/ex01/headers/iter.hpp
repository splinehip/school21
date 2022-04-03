/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:05:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/03 16:59:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void	print(T const &i)
{
	std::cout << i << std::endl;
}

template<typename T>
void	iter(T const *arr, unsigned int const &size, void (*f)(T const &i))
{
	unsigned int	i;

	i = 0;
	while (i < size)
		f(arr[i++]);
}
