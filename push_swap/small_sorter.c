/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:04:57 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/10 13:00:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack, char name)
{
	if (is_sorted(stack, ASCENDING, name))
		return ;
	if (s_idx(stack, name, 0) > s_idx(stack, name, 1))
		swap(stack, name);
}

void	sort_3(t_stack *stack, char name)
{
	if (is_sorted(stack, ASCENDING, name))
		return ;
	if (s_idx(stack, name, -1) == max_s_idx(stack, name))
	{
		if (s_idx(stack, name, 0) > s_idx(stack, name, 1))
			swap(stack, name);
	}
	else if (s_idx(stack, name, 1) == max_s_idx(stack, name))
	{
		if (name == A)
			ft_rotate(stack, RRA, 1);
		else
			ft_rotate(stack, RRB, 1);
		if (s_idx(stack, name, 0) > s_idx(stack, name, 1))
			swap(stack, name);
	}
	else if (s_idx(stack, name, 0) == max_s_idx(stack, name))
	{
		if (name == A)
			ft_rotate(stack, RA, 1);
		else
			ft_rotate(stack, RB, 1);
		if (s_idx(stack, name, 0) > s_idx(stack, name, 1))
			swap(stack, name);
	}
}

void	sort_4(t_stack *stack, char name)
{
	if (is_sorted(stack, ASCENDING, name))
		return ;
	while (is_sorted(stack, ASCENDING, name) == 0)
	{
		if (s_idx(stack, name, 0) > s_idx(stack, name, 1)
			&& s_idx(stack, name, 0) != max_s_idx(stack, name))
			swap(stack, name);
		if (is_sorted(stack, ASCENDING, name) == 0)
		{
			if (name == A)
				ft_rotate(stack, RA, 1);
			else
				ft_rotate(stack, RB, 1);
		}
	}
}

void	sort_5(t_stack *stack)
{
	int	max;

	max = max_s_idx(stack, A);
	while (1)
	{
		if (s_idx(stack, A, 0) == max || s_idx(stack, A, 0) == 0)
			push(stack, B, 1);
		if (stack->size_b == 2)
			break ;
		if (s_idx(stack, A, 0) != max && s_idx(stack, A, 0) != 0)
			ft_rotate(stack, RA, 1);
	}
	sort_3(stack, A);
	push(stack, A, 1);
	if (s_idx(stack, A, 0) == max)
		ft_rotate(stack, RA, 1);
	push(stack, A, 1);
	if (s_idx(stack, A, 0) == max)
		ft_rotate(stack, RA, 1);
}
