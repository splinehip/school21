/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:11:03 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/03 16:53:02 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	free_stack(t_stack *stack, int j)
{
	while (j >= 0)
	{
		free(stack->a[j]);
		free(stack->b[j]);
		free(stack->s[j--]);
	}
	free(stack->a);
	free(stack->b);
	free(stack->s);
}

static inline int	isalldigit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != 0)
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static inline int	invalid_number(t_stack *stack, char *s, int j)
{
	long int	tmp;

	tmp = ft_atol(s);
	if (tmp > -2147483649 && tmp < 2147483648)
	{
		*(stack->a[j]) = tmp;
		while (--j >= 0)
			if (*(stack->a[j]) == tmp)
				return (1);
		return (0);
	}
	return (1);
}

int	argv_handler(char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[++i] != NULL)
	{
		if (isalldigit(argv[i]))
		{
			stack->a[j] = ft_calloc(1, sizeof(int));
			stack->b[j] = ft_calloc(1, sizeof(int));
			stack->s[j] = ft_calloc(1, sizeof(int));
			if (invalid_number(stack, argv[i], j++))
			{
				free_stack(stack, --j);
				return (0);
			}
		}
		else
		{
			free_stack(stack, --j);
			return (0);
		}
	}
	return (1);
}
