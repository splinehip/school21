/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:34:38 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/07 17:55:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	sa(t_stack *stack, int print)
{
	int	tmp;

	if (print)
	{
		ft_printf("sa\n");
		stack->op += 1;
	}
	if (stack->size_a > 1)
	{
		tmp = *(stack->a[stack->size - stack->size_a]);
		*(stack->a[stack->size - stack->size_a])
			= *(stack->a[stack->size - stack->size_a + 1]);
		*(stack->a[stack->size - stack->size_a + 1]) = tmp;
	}
}

static inline void	sb(t_stack *stack, int print)
{
	int	tmp;

	if (print)
	{
		ft_printf("sb\n");
		stack->op += 1;
	}
	if (stack->size_b > 1)
	{
		tmp = get_by_idx(stack, B, 0);
		*(stack->b[stack->size - stack->size_b]) = get_by_idx(stack, B, 1);
		*(stack->b[stack->size - stack->size_b + 1]) = tmp;
	}
}

void	swap(t_stack *stack, int name)
{
	if (name == A)
		sa(stack, 1);
	else if (name == B)
		sb(stack, 1);
	else if (name == AB)
	{
		ft_printf("ss\n");
		sa(stack, 0);
		sb(stack, 0);
		stack->op += 1;
	}
}
