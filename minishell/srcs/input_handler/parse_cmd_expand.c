/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:19:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/08 17:07:23 by cflorind         ###   ########.fr       */
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
	printf("i: %i, l: %i\n", iter->i, iter->l);
	iter->name = ft_substr(cmd, iter->i, iter->l);
	iter->value = get_env_value(iter->name, env);
	printf("name: '%s', value: '%s'\n", iter->name, iter->value);
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
			if (drop_buf(cmd, iter) == unsucsses)
			{
				free(iter->value);
				return (unsucsses);
			}
		}
	}
	free(iter->value);
	return (sucsses);
}
