/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:29:28 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/10 13:18:25 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline void	a_to_b_handler(t_stack *stack)
{
	if (s_idx(stack, A, 0) <= stack->mid)
		push(stack, B, 1);
	if (s_idx(stack, A, 0) > stack->mid
		&& stack->size_b > 1 && s_idx(stack, B, 0) > stack->mid_next)
		ft_rotate(stack, RR, 1);
	else if (s_idx(stack, A, 0) > stack->mid)
		ft_rotate(stack, RA, 1);
}

static inline int	get_next_idx_in_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_b)
	{
		if (s_idx(stack, B, i) == stack->next)
			break ;
		i++;
	}
	return (stack->size - stack->size_b + i);
}

inline void	b_to_a_handler(t_stack *stack)
{
	if (s_idx(stack, B, 0) <= stack->mid)
		push(stack, A, 1);
	else
	{
		if (s_idx(stack, B, 1) <= stack->mid
			&& s_idx(stack, A, 0) <= stack->mid
			&& s_idx(stack, A, 1) != 0
			&& s_idx(stack, A, 1) != stack->unsort_top
			&& s_idx(stack, A, 0) > s_idx(stack, A, 1))
			swap(stack, AB);
		if (s_idx(stack, B, 0) > stack->mid
			&& s_idx(stack, B, -1) != stack->next)
			ft_rotate(stack, RB, 1);
		if (stack->size_b > 5
			&& stack->size - get_next_idx_in_b(stack) <= stack->size_b / 2)
			ft_rotate(
				stack, RRB, stack->size - get_next_idx_in_b(stack));
		if (stack->size_b <= 5)
			push(stack, A, 1);
	}
}

inline void	next_in_a_handler(t_stack *stack)
{
	if (s_idx(stack, A, 1) == stack->next)
		swap(stack, A);
	while (s_idx(stack, A, 0) == stack->next)
	{
		ft_rotate(stack, RA, 1);
		stack->next += 1;
		stack->sort_bot = s_idx(stack, A, -1);
		if ((s_idx(stack, A, 1) == stack->next
				&& stack->size_b > 3
				&& s_idx(stack, B, 0) > stack->mid
				&& s_idx(stack, B, 0) < stack->mid_next
				&& s_idx(stack, B, 1) <= stack->mid)
			|| (stack->size_b > 3
				&& s_idx(stack, B, 0) < stack->mid_next
				&& s_idx(stack, B, 0) > s_idx(stack, B, 1)))
			swap(stack, AB);
		else if (s_idx(stack, A, 1) == stack->next)
			swap(stack, A);
	}
}
