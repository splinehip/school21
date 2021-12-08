/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/08 16:03:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

static inline int	is_insertable(char c, t_iter *iter)
{
	if (iter->in_qoutes == single_quote)
		return (true);
	else if (iter->in_qoutes == quote && c != dollar)
		return (true);
	else if (iter->in_qoutes == false && c != dollar && c != escape)
		return (true);
	return (false);
}

static inline int	is_expandable(char c, t_iter *iter)
{
	if (iter->in_qoutes == single_quote)
		return (false);
	else if (c == dollar)
		return (true);
	return (false);
}

static inline char	*do_parse(char *cmd, char **env)
{
	t_iter	iter;

	iter.i = 0;
	iter.j = 0;
	iter.in_qoutes = false;
	iter.res = NULL;
	while (cmd[iter.i])
	{
		if (is_insertable(cmd[iter.i], &iter))
		{
			iter.buf[iter.j++] = cmd[iter.i];
			iter.buf[iter.j] = 0;
			iter.i++;
		}
		else if (is_expandable(cmd[iter.i++], &iter))
			if (do_expand(cmd, &iter, env) == unsucsses)
				break ;
		if (iter.j == BUF_SIZE || cmd[iter.i] == 0)
			if (drop_buf(&iter) == unsucsses)
				break ;
		printf("I: %i, BUF: '%s'\n", iter.i, iter.buf);
	}
	return (iter.res);
}

t_actions	*parse_cmd(char *cmd, char **env)
{
	t_actions	*actions;

	actions = NULL;
	cmd = do_parse(cmd, env);
	if (cmd == NULL)
	{
		ft_printf("Expanding var error.\n");
		return (actions);
	}
	ft_printf("EXPANDED CMD: '%s'\n", cmd);
	free(cmd);
	return (actions);
}
