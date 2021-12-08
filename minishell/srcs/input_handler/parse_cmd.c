/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/08 17:31:47 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

static inline int	is_insertable(char c, char *cmd, t_iter *iter)
{
	if (iter->in_qoutes == single_quote)
		return (true);
	else if (iter->in_qoutes == quote && c != dollar)
		return (true);
	else if (iter->in_qoutes == false && c != dollar && c != escape
		&& (c != space || cmd[iter->i - 1] != space))
		return (true);
	else if (c == dollar && cmd[iter->i - 1] == escape)
		return (true);
	return (false);
}

static inline int	is_expandable(char c, char *cmd, t_iter *iter)
{
	if (iter->in_qoutes == single_quote)
		return (false);
	else if (c == dollar)
	{
		if (iter->i == 0)
			return (true);
		if (cmd[iter->i - 2] != escape)
			return (true);
		return (false);
	}
	return (false);
}

static inline char	*do_parse(char *cmd, char **env)
{
	t_iter	iter;

	iter.i = 0;
	iter.j = 0;
	iter.in_qoutes = false;
	iter.res = NULL;
	while (cmd[iter.i] == space)
		iter.i++;
	while (cmd[iter.i])
	{
		if (is_insertable(cmd[iter.i], cmd, &iter))
		{
			iter.buf[iter.j++] = cmd[iter.i++];
			iter.buf[iter.j] = 0;
		}
		else if (is_expandable(cmd[iter.i++], cmd, &iter))
		{
			if (do_expand(cmd, &iter, env) == unsucsses)
				break ;
			iter.i += iter.l;
		}
		if (iter.j == BUF_SIZE || cmd[iter.i] == ends)
			if (drop_buf(cmd, &iter) == unsucsses)
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
		ft_printf("Parse cmd error.\n");
		return (actions);
	}
	ft_printf("EXPANDED CMD: '%s'\n", cmd);
	free(cmd);
	return (actions);
}
