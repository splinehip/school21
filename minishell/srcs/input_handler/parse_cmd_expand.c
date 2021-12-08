/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:19:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/08 15:20:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

static inline void	get_value(char *cmd, t_iter *iter, char **env)
{
	iter->l = iter->i;
	while (ft_isalnum(cmd[iter->l]))
		iter->l++;
	iter->l = iter->l - iter->i;
	printf("i: %i, l: %i\n", iter->i, iter->j);
	iter->name = ft_substr(cmd, iter->i, iter->l);
	iter->i = iter->i + iter->l;
	iter->value = get_env_value(iter->name, env);
	printf("name: '%s', value: '%s'\n", iter->name, iter->value);
	free(iter->name);
}

inline int	do_expand(
	char *cmd, t_iter *iter, char **env)
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
