/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:19:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/30 11:57:51 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "mesages.h"
#include "builtins.h"
#include "input_handler.h"

static inline void	get_value(char *cmd, t_iter *iter, char **env)
{
	iter->l = iter->i;
	if (cmd[iter->l + 1] == space || cmd[iter->l + 1] == dollar
		|| cmd[iter->l + 1] == ends)
	{
		iter->value = ft_strdup(MSG_DOLLAR);
		return ;
	}
	if (ft_isdigit(cmd[iter->l + 1]))
	{
		iter->l++;
		if (cmd[iter->l] == '0')
			iter->value = ft_strdup(MSG_PROG_NAME);
		else
			iter->value = NULL;
		return ;
	}
	while (ft_isalnum(cmd[iter->l + 1]) || cmd[iter->l + 1] == underscore
		|| cmd[iter->l + 1] == question)
		iter->l++;
	iter->name = ft_substr(cmd, iter->i + 1, iter->l - iter->i);
	iter->value = get_env_value(iter->name, env);
	if (iter->in_qoutes == quote && cmd[iter->l + 1] == quote)
		iter->l++;
	free(iter->name);
}

inline int	do_expand_env(
	char *cmd, t_iter *iter, char **env)
{
	int	i;

	get_value(cmd, iter, env);
	if (iter->value == NULL)
		return (success);
	i = 0;
	while (iter->value[i])
	{
		iter->buf[iter->j++] = iter->value[i++];
		iter->buf[iter->j] = 0;
		if (iter->j == BUF_SIZE)
		{
			if (do_drop_buf(&iter->res, &iter->buf[0], &iter->j) == unsuccess)
			{
				free(iter->value);
				return (unsuccess);
			}
		}
	}
	free(iter->value);
	return (success);
}
