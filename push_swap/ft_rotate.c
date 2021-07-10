/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:44:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/05 23:35:02 by cflorind         ###   ########.fr       */
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

static inline void	reverse_rotate(t_stack *stack, int count, char name,
	int print)
{
	int	i;
	int	**s;
	int	tmp;
	int	size;

	init(stack, name, &s, &size);
	if (size > 1 && print)
		stack->op += count;
	while (size > 1 && count-- != 0)
	{
		if (print)
			ft_printf("rr%c\n", name);
		i = stack->size;
		tmp = *s[i - 1];
		while (--i > stack->size - size)
			*s[i] = *s[i - 1];
		*s[stack->size - size] = tmp;
	}
}

static inline void	rotate(t_stack *stack, int count, char name, int print)
{
	int	i;
	int	**s;
	int	tmp;
	int	size;

	init(stack, name, &s, &size);
	if (size > 1 && print)
		stack->op += count;
	while (size > 1 && count-- != 0)
	{
		if (print)
			ft_printf("r%c\n", name);
		i = stack->size - size;
		tmp = *s[i];
		while (++i < stack->size)
			*s[i - 1] = *s[i];
		*s[i - 1] = tmp;
	}
}

void	ft_rotate(t_stack *stack, int rule, int count)
{
	if (rule == RA)
		rotate(stack, count, A, 1);
	else if (rule == RB)
		rotate(stack, count, B, 1);
	else if (rule == RR)
	{
		ft_printf("rr\n");
		rotate(stack, count, A, 0);
		rotate(stack, count, B, 0);
		stack->op += count;
	}
	else if (rule == RRA)
		reverse_rotate(stack, count, A, 1);
	else if (rule == RRB)
		reverse_rotate(stack, count, B, 1);
	else if (rule == RRR)
	{
		ft_printf("rrr\n");
		reverse_rotate(stack, count, A, 0);
		reverse_rotate(stack, count, B, 0);
		stack->op += count;
	}
	else
		ft_printf("ROTATE: INVALID RULE!\n");
}
