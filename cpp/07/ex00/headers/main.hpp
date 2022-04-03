/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:05:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/03 14:11:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const	&max(T const &a, T const &b)
{
	return (a >= b ? a : b);
}

template<typename T>
T const	&min(T const &a, T const &b)
{
	return (a <= b ? a : b);
}
