/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_do_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:31:00 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 20:28:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

static inline int	insertable_controls(char c, char *cmd, t_iter *iter)
{
	if (c == space)
	{
		if (cmd[iter->i - 1] == space && escaped(cmd, iter->i - 1))
			return (true);
		if (cmd[iter->i - 1] != space || escaped(cmd, iter->i))
			return (true);
	}
	if (c == escape)
	{
		if (iter->in_qoutes == false)
			if (escaped(cmd, iter->i))
				return (true);
		if (iter->in_qoutes == quote)
			if (escaped(cmd, iter->i)
				|| (escaped(cmd, iter->i) == false
					&& cmd[iter->i + 1] != quote
					&& cmd[iter->i + 1] != escape
					&& cmd[iter->i + 1] != dollar))
				return (true);
	}
	if (escaped(cmd, iter->i))
		return (true);
	return (false);
}

static inline int	insertable(char c, char *cmd, t_iter *iter)
{
	if (iter->in_qoutes == single_quote)
		if (c != single_quote)
			return (true);
	if (iter->in_qoutes == quote)
	{
		if (c != quote && c != escape && c != dollar)
			return (true);
		if (insertable_controls(c, cmd, iter))
			return (true);
	}
	if (iter->in_qoutes == false)
	{
		if (c != space && c != escape && c != dollar)
			return (true);
		else if (insertable_controls(c, cmd, iter))
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
		if (escaped(cmd, iter->i) == false)
			return (true);
	}
	return (false);
}

static inline int	init_iter(char **cmd, t_iter *iter)
{
	int	i;

	if (*cmd == NULL)
		return (false);
	iter->i = 0;
	iter->j = 0;
	iter->k = 0;
	iter->in_qoutes = false;
	while (**cmd != ends && **cmd == space)
		*cmd += 1;
	i = ft_strlen(*cmd);
	while (--i >= 0 && (*cmd)[i] != ends && (*cmd)[i] == space)
		(*cmd)[i] = ends;
	if (ft_strlen(*cmd) == 0)
		iter->res = ft_calloc(1, sizeof(char));
	else
		iter->res = NULL;
	return (true);
}

inline char	*do_parse(char *cmd, char **env)
{
	t_iter	iter;

	iter.init_res = init_iter(&cmd, &iter);
	while (iter.init_res && cmd[iter.i])
	{
		do_check_quotes(cmd, &iter);
		if (insertable(cmd[iter.i], cmd, &iter))
		{
			iter.buf[iter.j++] = cmd[iter.i];
			iter.buf[iter.j] = ends;
		}
		else if (expandable(cmd[iter.i], cmd, &iter))
		{
			if (do_expand_env(cmd, &iter, env) == unsucsses)
				break ;
			iter.i = iter.l;
			if (iter.i >= iter.k)
				iter.k = iter.i + 1;
		}
		if (iter.j == BUF_SIZE || cmd[iter.i + 1] == ends)
			if (do_drop_buf(&iter.res, &iter.buf[0], &iter.j))
				break ;
		iter.i++;
	}
	return (iter.res);
}
