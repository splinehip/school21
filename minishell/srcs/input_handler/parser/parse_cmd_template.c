/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_template.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:36:13 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/15 15:53:30 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

enum e_direction
{
	left,
	rigth,
};

static inline int	idx(int i, int direction)
{
	if (direction == left)
		return (i - 1);
	return (i + 1);
}

static inline int	find(char *cmd, t_extract *args, int *i, int direction)
{
	int		quot_count;
	char	quot_type;

	quot_count = 0;
	quot_type = 0;
	while (cmd[*i] != ends && cmd[*i] >= args->prev_end)
	{
		if (cmd[idx(*i, direction)] == space
			&& escaped(cmd, idx(*i, direction)) == false
			&& quot_count % 2 == 0)
			break ;
		if (cmd[idx(*i, direction)] == quote
			|| cmd[idx(*i, direction)] == single_quote)
		{
			if (quot_type == 0)
				quot_type = cmd[idx(*i, direction)];
			if (cmd[idx(*i, direction)] == quot_type)
				quot_count++;
		}
		if (direction == left && *i == args->prev_end)
			break ;
		*i = idx(*i, direction);
	}
	return (quot_count);
}

inline int	get_template_border(char *cmd, t_extract *args)
{
	int	quoted_left;
	int	quoted_right;

	args->start = args->pchar - cmd;
	quoted_left = find(cmd, args, &args->start, left);
	args->end = args->pchar - cmd;
	quoted_right = find(cmd, args, &args->end, rigth);
	ft_printf("ql: %i, qr: %i\nstart: %i, end: %i\n", quoted_left, quoted_right,
		args->start, args->end);
	if (quoted_left % 2 == 0 && quoted_right % 2 == 0)
		return (sucsses);
	return (unsucsses);
}
