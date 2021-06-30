/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:54:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/30 12:12:17 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	init(t_stack *stack, char name, int ***s, int *size)
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

int	is_sorted(t_stack *stack, int dir, char name)
{
	int	i;
	int	**s;
	int	size;

	init(stack, name, &s, &size);
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
