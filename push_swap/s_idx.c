/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_idx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:41:29 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/09 14:50:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_idx(t_stack *stack, char name, int idx)
{
	int	i;
	int	item;

	i = 0;
	item = get_by_idx(stack, name, idx);
	while (i < stack->size && *(stack->s[i]) != item)
		i++;
	return (i);
}

int	max_s_idx(t_stack *stack, char name)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (name == A && i < stack->size_a)
	{
		if (s_idx(stack, name, i) > res)
			res = s_idx(stack, name, i);
		i++;
	}
	while (name == B && i < stack->size_b)
	{
		if (s_idx(stack, name, i) > res)
			res = s_idx(stack, name, i);
		i++;
	}
	return (res);
}

int	mid_s_idx(t_stack *stack, char name)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (name == A && stack->size_a == 0)
		return (res);
	if (name == B && stack->size_b == 0)
		return (res);
	while (name == A && i < stack->size_a)
		res += s_idx(stack, name, i++);
	while (name == B && i < stack->size_b)
		res += s_idx(stack, name, i++);
	return (res / i + 1);
}

void	sort_s(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;
	int	size;

	i = 0;
	size = 0;
	while (i < stack->size)
	{
		*(stack->s[stack->size - ++size]) = *(stack->a[i++]);
		j = stack->size - size;
		while (size > 1 && j < stack->size - 1
			&& *(stack->s[j]) > *(stack->s[j + 1]))
		{
			tmp = *(stack->s[j]);
			*(stack->s[j]) = *(stack->s[j + 1]);
			*(stack->s[j + 1]) = tmp;
			j++;
		}
	}
}
