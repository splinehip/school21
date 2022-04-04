/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:34:17 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/04 12:59:54 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<template<typename, typename> class T>
int	easyfind(T<int, std::allocator<int> > &arr, int i)
{
	typename T<int, std::allocator<int> >::iterator it;

	it = std::find(arr.begin(), arr.end(), i);
	if (it == arr.end())
		return (-1);
	return (std::distance(arr.begin(), it));
}
