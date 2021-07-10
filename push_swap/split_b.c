/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:39:53 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/10 13:19:25 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	have_to_push(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_b)
	{
		if (s_idx(stack, B, i) <= stack->mid)
			break ;
		i++;
	}
	return (i < stack->size_b);
}

static inline int	b_have_next(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_b)
	{
		if (s_idx(stack, B, i) == stack->next)
			break ;
		i++;
	}
	return (i < stack->size_b);
}

static inline void	next_to_b_handler(t_stack *stack)
{
	if (stack->next < stack->size && b_have_next(stack) == 0)
	{
		while (s_idx(stack, A, 0) != stack->unsort_top)
		{
			if (s_idx(stack, A, 0) != stack->unsort_top
				&& s_idx(stack, A, 0) != stack->next)
				push(stack, B, 1);
			next_in_a_handler(stack);
			if (b_have_next(stack))
				break ;
		}
		stack->mid = mid_s_idx(stack, B);
		stack->mid_next = stack->mid / 2;
	}
}

inline void	split_b(t_stack *stack)
{
	stack->mid = mid_s_idx(stack, B);
	stack->mid_next = stack->mid / 2;
	while (have_to_push(stack))
	{
		b_to_a_handler(stack);
		next_in_a_handler(stack);
		next_to_b_handler(stack);
	}
}
