/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:53:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/09 21:49:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline int	get_by_idx(t_stack *stack, char name, int idx)
{
	if (name == A)
	{
		if (idx < 0)
		{
			if (stack->size + idx < stack->size - stack->size_a)
				return (*(stack->a[-1]));
			return (*(stack->a[stack->size + idx]));
		}
		return (*(stack->a[stack->size - stack->size_a + idx]));
	}
	else
	{
		if (idx < 0)
		{
			if (stack->size + idx < stack->size - stack->size_b)
				return (*(stack->b[-1]));
			return (*(stack->b[stack->size + idx]));
		}
		return (*(stack->b[stack->size - stack->size_b + idx]));
	}
}

inline int	mid_unsorted(t_stack *stack)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s_idx(stack, A, i) != 0)
		res += s_idx(stack, A, i++);
	return (res / i - 1);
}

inline int	unsroted_length(t_stack *stack)
{
	int	i;

	i = 0;
	while (s_idx(stack, A, i) != 0)
		i++;
	return (i);
}

static inline void	is_sorted_init(
								t_stack *stack, char name, int ***s, int *size)
{
	if (name == A)
	{
		*size = stack->size_a;
		*s = stack->a;
	}
	if (name == B)
	{
		*size = stack->size_b;
		*s = stack->b;
	}
}

inline int	is_sorted(t_stack *stack, int dir, char name)
{
	int	i;
	int	**s;
	int	size;

	is_sorted_init(stack, name, &s, &size);
	i = stack->size - size;
	if (dir == ASCENDING)
	{
		while (i < stack->size - 1)
		{
			if (*s[i] > *s[i + 1])
				return (0);
			i++;
		}
	}
	if (dir == DESCENDING)
	{
		while (i < stack->size - 1)
		{
			if (*s[i] < *s[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}
