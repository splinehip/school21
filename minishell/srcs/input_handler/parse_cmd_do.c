/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:31:00 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/12 15:20:36 by cflorind         ###   ########.fr       */
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
	else if (c == escape)
	{
		if (iter->in_qoutes == false && escaped(cmd, iter->i))
			return (true);
		else if (iter->in_qoutes == false
			&& escaped(cmd, iter->i) == false && cmd[iter->i + 1] == ends)
			return (true);
		if (iter->in_qoutes == quote)
			if (escaped(cmd, iter->i))
				return (true);
	}
	else if (escaped(cmd, iter->i))
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
