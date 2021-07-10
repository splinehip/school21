/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:04:23 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/10 10:56:34 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack)
{
	stack->next = 0;
	first_split_a(stack);
	stack->unsort_top = s_idx(stack, A, 0);
	while (stack->next < stack->size)
	{
		split_b(stack);
		split_remain_unsorted_a(stack);
	}
}
