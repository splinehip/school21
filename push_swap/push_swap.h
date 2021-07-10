#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define RA 0
# define RB 1
# define RRA 2
# define RRB 3
# define RR 4
# define RRR 5
# define A 'a'
# define B 'b'
# define AB 0
# define ASCENDING 1
# define DESCENDING 0
# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>

typedef struct s_stack
{
	int	**a;
	int	**b;
	int	**s;
	int	size;
	int	size_a;
	int	size_b;
	int	op;
	int	mid;
	int	mid_next;
	int	next;
	int	sort_bot;
	int	unsort_top;
}		t_stack;

int		argv_handler(char **argv, t_stack *stack);
int		find_largest(int **stack, int size, int stack_size);
int		find_smallest(int **stack, int size, int stack_size);
int		is_sorted(t_stack *stack, int dir, char name);
void	ft_rotate(t_stack *stack, int rule, int count);
void	push(t_stack *stack, char name, int count);
void	swap(t_stack *stack, int name);
void	sort_stack(t_stack *stack);
void	sort_s(t_stack *stack);
int		s_idx(t_stack *stack, char name, int idx);
int		get_by_idx(t_stack *stack, char name, int idx);
void	first_split_a(t_stack *stack);
void	split_remain_unsorted_a(t_stack *stack);
void	a_to_b_handler(t_stack *stack);
void	split_b(t_stack *stack);
void	b_to_a_handler(t_stack *stack);
void	next_in_a_handler(t_stack *stack);
int		max_s_idx(t_stack *stack, char name);
int		mid_s_idx(t_stack *stack, char name);
int		mid_unsorted(t_stack *stack);
int		unsroted_length(t_stack *stack);
void	sort_2(t_stack *stack, char name);
void	sort_3(t_stack *stack, char name);
void	sort_4(t_stack *stack, char name);
void	sort_5(t_stack *stack);
void	print_stack(t_stack *stack);

#endif
