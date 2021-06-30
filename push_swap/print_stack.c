#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->size - stack->size_a;
	j = stack->size - stack->size_b;
	ft_printf("\n");
	while ((stack->size_a >= stack->size_b) && i < stack->size)
	{
		ft_printf("%i", *(stack->a[i]));
		if (j == i++)
			ft_printf("\t%i", *(stack->b[j++]));
		ft_printf("\n");
	}
	while (j < stack->size)
	{
		if (i == j)
			ft_printf("%i", *(stack->a[i++]));
		ft_printf("\t%i\n", *(stack->b[j++]));
	}
	ft_printf("--\t--\nstack_a\tstack_b\n\n");
}
