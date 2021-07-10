/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:40:53 by cflorind          #+#    #+#             */
/*   Updated: 2021/07/10 13:16:55 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	free_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		free(stack->a[i]);
		free(stack->b[i]);
		free(stack->s[i++]);
	}
	free(stack->a);
	free(stack->b);
	free(stack->s);
}

static inline int	is_shorted(t_stack *stack)
{
	if (stack->size > 5)
		return (0);
	if (stack->size == 2)
		sort_2(stack, A);
	if (stack->size == 3)
		sort_3(stack, A);
	if (stack->size == 4)
		sort_4(stack, A);
	if (stack->size == 5)
		sort_5(stack);
	return (1);
}

static inline void	get_res(t_stack *stack)
{
	int	i;

	if (is_sorted(stack, ASCENDING, A))
		return ;
	sort_s(stack);
	if (is_sorted(stack, DESCENDING, A))
	{
		if (is_shorted(stack))
			return ;
		i = 0;
		push(stack, B, stack->size);
		while (i++ < stack->size)
		{
			ft_rotate(stack, RRB, 1);
			push(stack, A, 1);
		}
		return ;
	}
	if (is_shorted(stack))
		return ;
	sort_stack(stack);
}

static inline void	init_stack(t_stack *stack, int size)
{
	stack->size = size;
	stack->size_a = size;
	stack->size_b = 0;
	stack->op = 0;
	stack->a = (int **)ft_calloc(size, sizeof(int *));
	stack->b = (int **)ft_calloc(size, sizeof(int *));
	stack->s = (int **)ft_calloc(size, sizeof(int *));
	if (stack->a == NULL || stack->b == NULL || stack->s == NULL)
	{
		free(stack->a);
		free(stack->b);
		free(stack->s);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1 || argv == NULL)
		exit(EXIT_FAILURE);
	init_stack(&stack, argc - 1);
	if (argv_handler(argv, &stack))
		get_res(&stack);
	else
	{
		ft_putendl_fd("Error", 2);
		exit(EINVAL);
	}
	free_stack(&stack);
	exit(EXIT_SUCCESS);
}
