/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:19:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/12 19:49:11 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

static inline void	get_value(char *cmd, t_iter *iter, char **env)
{
	iter->l = iter->i;
	if (cmd[iter->l + 1] == '0')
	{
		iter->l++;
		iter->value = ft_strdup("minishell");
		return ;
	}
	while (ft_isalnum(cmd[iter->l + 1]))
		iter->l++;
	iter->name = ft_substr(cmd, iter->i + 1, iter->l - iter->i);
	iter->value = get_env_value(iter->name, env);
	if (iter->in_qoutes == quote && cmd[iter->l + 1] == quote)
		iter->l++;
	free(iter->name);
}

inline int	do_expand(
	char *cmd, t_iter *iter, char **env)
{
	int	i;

	get_value(cmd, iter, env);
	if (iter->value == NULL)
		return (sucsses);
	i = 0;
	while (iter->value[i])
	{
		iter->buf[iter->j++] = iter->value[i++];
		iter->buf[iter->j] = 0;
		if (iter->j == BUF_SIZE)
		{
			if (drop_buf(iter) == unsucsses)
			{
				free(iter->value);
				return (unsucsses);
			}
		}
	}
	free(iter->value);
	return (sucsses);
}
