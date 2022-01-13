/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/13 16:34:02 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "input_handler.h"
#include "actions_handler.h"
#include "minishell.h"

void	insert_separators(char **upd, int i)
{
	char	opened_quote;

	opened_quote = 0;
	while ((*upd)[i])
	{
		if (!opened_quote)
		{
			if (((*upd)[i] == quote || (*upd)[i] == single_quote)
				&& escaped(*upd, i) == false)
				opened_quote = (*upd)[i];
			if ((*upd)[i] == space)
				(*upd)[i] = SEPARATOR;
		}
		else
		{
			if ((*upd)[i] == opened_quote)
				opened_quote = 0;
		}
		i++;
	}
}

char	**split_cmd(char *cmd, char **env)
{
	char	**split_cmds;
	char	*tmp;
	int		i;

	i = 0;
	insert_separators(&cmd, i);
	split_cmds = ft_split(cmd, SEPARATOR);
	while (split_cmds && split_cmds[i])
	{
		if (*split_cmds[i] == asterisk && ft_strlen(split_cmds[i]) == 1)
			tmp = parse_cmd(split_cmds[i], env, asterisk);
		else
			tmp = parse_cmd(split_cmds[i], env, false);
		free(split_cmds[i]);
		split_cmds[i] = tmp;
		i++;
	}
	return (split_cmds);
}

t_actions	*do_actions_build(t_actions *actions, char *cmd, char ***env)
{
	char	**splited_cmd;

	splited_cmd = split_cmd(cmd, *env);
	if (splited_cmd == NULL)
		return (actions);
	return (do_build_items(actions, &splited_cmd, *env));
}
