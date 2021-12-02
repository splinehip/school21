/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:23:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/02 18:24:34 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "bool.h"
#include "input_handler.h"

static const char	*action_name(t_actions *actions)
{
	if (actions->type == expand)
		return ("expand");
	else if (actions->type == builtin)
		return ("builtin");
	else if (actions->type == execute)
		return ("execute");
	else if (actions->type == exec_pipe)
		return ("exec_pipe");
	else
		return ("Undefined");
}

static inline void	print_res(t_actions *actions)
{
	printf("ACTION: %s\n", action_name(actions));
	free(actions);
}

int	input_handler(char **argv)
{
	printf("symbol: %c (code: %i)\n", quote, quote);
	printf("symbol: %c (code: %i)\n", single_quote, single_quote);
	printf("symbol: %c (code: %i)\n", left_corner, left_corner);
	printf("symbol: %c (code: %i)\n", right_corner, right_corner);
	printf("symbol: %c (code: %i)\n", pipes, pipes);
	printf("symbol: %c (code: %i)\n", env_var, env_var);
	test_func();
	print_res(parser(argv));
	return (0);
}
