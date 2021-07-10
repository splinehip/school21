#include "push_swap.h"

static inline void	print(t_stack *stack, int i, int j)
{
	while ((stack->size_a >= stack->size_b) && i < stack->size)
	{
		ft_printf("%i\t[%i]", *(stack->a[i]),
			s_idx(stack, A, i + stack->size_a - stack->size));
		if (j == i++ && j++)
			ft_printf("\t\t%i\t[%i]", *(stack->b[j - 1]),
				s_idx(stack, B, j - 1 + stack->size_b - stack->size));
		ft_printf("\n");
	}
	while (j < stack->size)
	{
		if (i == j++ && i++)
			ft_printf("%i\t[%i]", *(stack->a[i - 1]),
				s_idx(stack, A, i - 1 + stack->size_a - stack->size));
		else
			ft_printf("\t");
		ft_printf("\t\t%i\t[%i]\n", *(stack->b[j - 1]),
			s_idx(stack, B, j - 1 + stack->size_b - stack->size));
	}
}

void	print_stack(t_stack *stack)
{
	int	i;
	int	j;

	write(STDOUT_FILENO, "\e[1;1H\e[2J", 12);
	i = stack->size - stack->size_a;
	j = stack->size - stack->size_b;
	ft_printf("\n");
	print(stack, i, j);
	ft_printf("--\t--\t\t--\t--\na_stack\tidx\t\tb_stack\tidx\n\n");
}
