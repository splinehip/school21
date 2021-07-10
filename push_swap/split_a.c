/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:08:42 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/10 10:21:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline void	first_split_a(t_stack *stack)
{
	int	i;

	stack->mid = mid_s_idx(stack, A);
	stack->mid_next = stack->mid / 2;
	i = 0;
	while (i != stack->size_a)
	{
		a_to_b_handler(stack);
		i = 0;
		while (i < stack->size_a)
		{
			if (s_idx(stack, A, i) <= stack->mid)
				break ;
			i++;
		}
	}
}

inline void	split_remain_unsorted_a(t_stack *stack)
{
	if (stack->size_b == 0 && stack->next < stack->size
		&& unsroted_length(stack) < 45)
	{
		while (s_idx(stack, A, 0) != 0)
		{
			next_in_a_handler(stack);
			if (s_idx(stack, A, 0) != 0)
				push(stack, B, 1);
		}
		stack->unsort_top = 0;
	}
	else if (stack->size_b == 0 && stack->next < stack->size)
	{
		stack->mid = mid_unsorted(stack);
		stack->mid_next = stack->mid / 2;
		while (s_idx(stack, A, 0) != 0)
			a_to_b_handler(stack);
		while (s_idx(stack, A, -1) != stack->sort_bot)
			ft_rotate(stack, RRA, 1);
		stack->unsort_top = s_idx(stack, A, 0);
	}
}
