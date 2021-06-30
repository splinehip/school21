/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:26:50 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/29 11:24:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_largest(int **stack, int size, int stack_size)
{
	int	i;
	int	res;
	int	largest;

	i = size - stack_size;
	res = i;
	largest = *stack[i];
	while (i < size)
	{
		if (*stack[i] > largest)
		{
			res = i;
			largest = *stack[i];
		}
		i++;
	}
	return (res);
}
