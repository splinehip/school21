/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:54:34 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/06 18:53:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack, int count)
{
	if (count <= 0 || stack->size_b == 0)
		return ;
	stack->op += count;
	while (count-- != 0 && stack->size_b != 0)
	{
		ft_printf("pa\n");
		*(stack->a[stack->size - stack->size_a - 1])
			= *(stack->b[stack->size - stack->size_b]);
		stack->size_b -= 1;
		stack->size_a += 1;
	}
}

void	push_b(t_stack *stack, int count)
{
	if (count <= 0 || stack->size_a == 0)
		return ;
	stack->op += count;
	while (count-- != 0 && stack->size_a != 0)
	{
		ft_printf("pb\n");
		*(stack->b[stack->size - stack->size_b - 1])
			= *(stack->a[stack->size - stack->size_a]);
		stack->size_b += 1;
		stack->size_a -= 1;
	}
}

void	push(t_stack *stack, char name, int count)
{
	if (name == 'a')
		push_a(stack, count);
	else
		push_b(stack, count);
}
