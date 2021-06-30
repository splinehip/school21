/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:44:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/29 12:12:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	init(t_stack *stack, char name, int ***s, int *size)
{
	if (name == 'a')
	{
		*s = stack->a;
		*size = stack->size_a;
	}
	else
	{
		*s = stack->b;
		*size = stack->size_b;
	}
}

static inline void	reverse_rotate(t_stack *stack, int count, char name)
{
	int	i;
	int	**s;
	int	tmp;
	int	size;

	init(stack, name, &s, &size);
	while (size > 1 && count-- != 0)
	{
		ft_printf("rr%c\n", name);
		i = stack->size;
		tmp = *s[i - 1];
		while (--i > stack->size - size)
			*s[i] = *s[i - 1];
		*s[stack->size - size] = tmp;
	}
}

static inline void	rotate(t_stack *stack, int count, char name)
{
	int	i;
	int	**s;
	int	tmp;
	int	size;

	init(stack, name, &s, &size);
	while (size > 1 && count-- != 0)
	{
		ft_printf("r%c\n", name);
		i = stack->size - size;
		tmp = *s[i];
		while (++i < stack->size)
			*s[i - 1] = *s[i];
		*s[i - 1] = tmp;
	}
}

void	ft_rotate(t_stack *stack, int count, int dir, char name)
{
	if (dir)
		reverse_rotate(stack, count, name);
	else
		rotate(stack, count, name);
}
