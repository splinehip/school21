/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:40:53 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/30 12:08:25 by cflorind         ###   ########.fr       */
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
		free(stack->b[i++]);
	}
	free(stack->a);
	free(stack->b);
}

static inline void	get_res(t_stack *stack)
{
	int	i;

	if (is_sorted(stack, ASCENDING, A))
		return ;
	if (is_sorted(stack, DESCENDING, A))
	{
		i = 0;
		while (i++ < stack->size)
		{
			ft_rotate(stack, 1, RR, A);
			push(stack, 1, B);
		}
		push(stack, stack->size, A);
		return ;
	}
	sort_stack(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1 || argv == NULL)
		exit(EXIT_FAILURE);
	stack.size = argc - 1;
	stack.size_a = stack.size;
	stack.size_b = 0;
	stack.a = (int **)ft_calloc(argc - 1, sizeof(int *));
	stack.b = (int **)ft_calloc(argc - 1, sizeof(int *));
	if (stack.a == NULL || stack.b == NULL)
	{
		free(stack.a);
		free(stack.b);
		exit(EXIT_FAILURE);
	}
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
