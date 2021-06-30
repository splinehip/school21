/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:34:38 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/29 12:42:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char name)
{
	int	tmp;

	if (name == 'a' && stack->size_a > 1)
	{
		ft_printf("sa\n");
		tmp = *(stack->a[stack->size - stack->size_a]);
		*(stack->a[stack->size - stack->size_a])
			= *(stack->a[stack->size - stack->size_a + 1]);
		*(stack->a[stack->size - stack->size_a + 1]) = tmp;
	}
	if (name == 'b' && stack->size_b > 1)
	{
		ft_printf("sb\n");
		tmp = *(stack->b[stack->size - stack->size_b]);
		*(stack->b[stack->size - stack->size_b])
			= *(stack->b[stack->size - stack->size_b + 1]);
		*(stack->b[stack->size - stack->size_b + 1]) = tmp;
	}
}
