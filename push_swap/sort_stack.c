/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:04:23 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/30 12:07:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	largest_to_top(t_stack *stack, char name)
{
	int	size;
	int	largest;

	if (name == A)
	{
		size = stack->size_a;
		largest = find_largest(stack->a, stack->size, stack->size_a);
	}
	if (name == B)
	{
		size = stack->size_b;
		largest = find_largest(stack->b, stack->size, stack->size_b);
	}
	if (largest == stack->size - size)
		return ;
	else if (stack->size - largest < largest - (stack->size - size))
		ft_rotate(stack, stack->size - largest, RR, name);
	else
		ft_rotate(stack, largest - (stack->size - size), R, name);
}

static inline int	stack_sorted(t_stack *stack, char name, char name_to)
{
	int	i;

	if (name == A)
		i = stack->size_a;
	if (name == B)
		i = stack->size_b;
	if (is_sorted(stack, ASCENDING, name))
	{
		while (i-- != 0)
		{
			ft_rotate(stack, 1, RR, name);
			push(stack, 1, name_to);
		}
		return (1);
	}
	if (is_sorted(stack, DESCENDING, name))
	{
		push(stack, i, name_to);
		return (1);
	}
	return (0);
}

void	sort_stack(t_stack *stack)
{
	int	largest;

	largest = find_largest(stack->a, stack->size, stack->size_a);
	if (largest == 0)
		ft_rotate(stack, 1, R, A);
	else if (largest != stack->size - 1 && stack->size - largest < largest)
		ft_rotate(stack, stack->size - (largest + 1), RR, A);
	else if (largest != stack->size - 1)
		ft_rotate(stack, largest + 1, R, A);
	if (is_sorted(stack, ASCENDING, A))
		return ;
	push(stack, stack->size - 1, B);
	if (stack_sorted(stack, B, A))
		return ;
	while (stack->size_b != 0)
	{
		largest_to_top(stack, B);
		push(stack, 1, A);
		if (stack_sorted(stack, B, A))
			return ;
	}
}
