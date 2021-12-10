/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:31:00 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/10 18:33:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

static inline int	insertable_space_or_escape(char c, char *cmd, t_iter *iter)
{
	if (c == space)
	{
		if (iter->i - 1 != 0
			&& cmd[iter->i - 1] == space && cmd[iter->i - 2] == escape)
			return (true);
		if (cmd[iter->i - 1] != space || cmd[iter->i - 1] == escape)
			return (true);
	}
	else if (c == escape && iter->i && cmd[iter->i - 1] == escape
		&& cmd[iter->i + 1] != escape)
		return (true);
	return (false);
}

static inline int	insertable(char c, char *cmd, t_iter *iter)
{
	if (iter->in_qoutes == single_quote)
		if ((c != single_quote && c != escape)
			|| (c == escape && cmd[iter->i + 1] != single_quote)
			|| (c == single_quote && iter->i && cmd[iter->i - 1] == escape))
			return (true);
	if (iter->in_qoutes == quote)
		if ((c != escape && c != quote && c != dollar)
			|| (c == escape && cmd[iter->i + 1] != quote)
			|| ((c == quote || c == dollar)
				&& iter->i && cmd[iter->i - 1] == escape))
			return (true);
	if (iter->in_qoutes == false)
	{
		if (c != space && c != escape && c != dollar)
			return (true);
		if (c == space || c == escape)
			if (insertable_space_or_escape(c, cmd, iter))
				return (true);
		if (c == dollar && iter->i && cmd[iter->i - 1] == escape)
			return (true);
	}
	return (false);
}

static inline int	expandable(char c, char *cmd, t_iter *iter)
{
	if (c == dollar)
	{
		if (iter->i == 0)
			return (true);
		if (cmd[iter->i - 1] != escape)
			return (true);
	}
	return (false);
}

static inline void	init_iter(char **cmd, t_iter *iter)
{
	int	i;

	iter->i = 0;
	iter->j = 0;
	iter->k = 0;
	iter->in_qoutes = false;
	iter->res = NULL;
	while (**cmd != ends && **cmd == space)
		*cmd += 1;
	i = ft_strlen(*cmd);
	while (--i >= 0 && (*cmd)[i] != ends && (*cmd)[i] == space)
		(*cmd)[i] = ends;
}

inline char	*do_parse(char *cmd, char **env)
{
	t_iter	iter;

	init_iter(&cmd, &iter);
	while (cmd[iter.i])
	{
		check_quotes(cmd, &iter);
		if (insertable(cmd[iter.i], cmd, &iter))
		{
			iter.buf[iter.j++] = cmd[iter.i];
			iter.buf[iter.j] = ends;
		}
		else if (expandable(cmd[iter.i], cmd, &iter))
		{
			if (do_expand(cmd, &iter, env) == unsucsses)
				break ;
			iter.i = iter.l;
			if (iter.i >= iter.k)
				iter.k = iter.i + 1;
		}
		if (iter.j == BUF_SIZE || cmd[iter.i + 1] == ends)
			if (drop_buf(&iter) == unsucsses)
				break ;
		iter.i++;
	}
	return (iter.res);
}
