/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:19:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/08 13:41:21 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

struct s_iter
{
	int		i;
	int		j;
	int		l;
	char	buf[BUF_SIZE];
	char	*name;
	char	*value;
	char	*res;
};

static inline int	drop_buf(struct s_iter *iter)
{
	char	*tmp;

	tmp = iter->res;
	iter->res = ft_strjoin(iter->res, iter->buf);
	free(tmp);
	iter->j = 0;
	if (iter->res == NULL)
		return (unsucsses);
	return (sucsses);
}

static inline void	get_value(char *cmd, struct s_iter *iter, char **env)
{
	iter->l = iter->i;
	while (cmd[iter->l] != quote
		&& cmd[iter->l] != left_corner
		&& cmd[iter->l] != right_corner
		&& cmd[iter->l] != escape
		&& cmd[iter->l] != pipes
		&& cmd[iter->l] != expand_var
		&& cmd[iter->l] != space
		&& cmd[iter->l] != endl)
		iter->l++;
	iter->l = iter->l - iter->i;
	printf("i: %i, l: %i\n", iter->i, iter->j);
	iter->name = ft_substr(cmd, iter->i, iter->l);
	iter->i = iter->i + iter->l;
	iter->value = get_env_value(iter->name, env);
	printf("name: '%s', value: '%s'\n", iter->name, iter->value);
	free(iter->name);
}

static inline int	insert_var(
	char *cmd, struct s_iter *iter, char **env)
{
	get_value(cmd, iter, env);
	if (iter->value == NULL)
		return (sucsses);
	iter->l = 0;
	while (iter->value[iter->l])
	{
		iter->buf[iter->j++] = iter->value[iter->l++];
		iter->buf[iter->j] = 0;
		if (iter->j == BUF_SIZE)
		{
			if (drop_buf(iter) == false)
			{
				free(iter->value);
				return (unsucsses);
			}
		}
	}
	free(iter->value);
	return (sucsses);
}

char	*expand_vars(char *cmd, char **env)
{
	struct s_iter	iter;

	if (ft_strchr(cmd, expand_var) == NULL)
		return (ft_strdup(cmd));
	iter.i = 0;
	iter.j = 0;
	iter.res = NULL;
	while (cmd[iter.i])
	{
		if (cmd[iter.i] != expand_var)
		{
			iter.buf[iter.j++] = cmd[iter.i++];
			iter.buf[iter.j] = 0;
		}
		else
		{
			iter.i++;
			if (insert_var(cmd, &iter, env) == unsucsses)
				break ;
		}
		if (iter.j == BUF_SIZE || cmd[iter.i] == 0)
			if (drop_buf(&iter) == unsucsses)
				break ;
		printf("I: %i, BUF: '%s'\n", iter.i, iter.buf);
	}
	return (iter.res);
}
