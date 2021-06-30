#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define R 0
# define RR 1
# define A 'a'
# define B 'b'
# define ASCENDING 1
# define DESCENDING 0
# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>

typedef struct s_stack
{
	int	**a;
	int	**b;
	int	size;
	int	size_a;
	int	size_b;
}		t_stack;

int		argv_handler(char **argv, t_stack *stack);
int		find_largest(int **stack, int size, int stack_size);
int		is_sorted(t_stack *stack, int dir, char name);
void	ft_rotate(t_stack *stack, int count, int dir, char name);
void	push(t_stack *stack, int count, char name);
void	swap(t_stack *stack, char name);
void	sort_stack(t_stack *stack);
void	print_stack(t_stack *stack);

#endif
