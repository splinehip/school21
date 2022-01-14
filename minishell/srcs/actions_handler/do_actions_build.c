/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/14 12:52:18 by lbaela           ###   ########.fr       */
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

static inline void	on_closed_quotes(char *cmd, char **new, int i, int *j)
{
	if (i && (((cmd[i] == r_crnr || cmd[i] == l_crnr)
				&& cmd[i] != cmd[i - 1]) || cmd[i] == pipes))
		(*new)[(*j)++] = SEPARATOR;
	if (cmd[i] == space && !escaped(cmd, i))
		(*new)[(*j)++] = SEPARATOR;
	else
		(*new)[(*j)++] = cmd[i];
	if (cmd[i] == pipes)
		(*new)[(*j)++] = SEPARATOR;
}

static inline void	copy_with_separators(char **new, char *cmd, int i, int j)
{
	char	opened_quote;

	opened_quote = 0;
	while (cmd[i])
	{
		if (!opened_quote)
		{
			if ((cmd[i] == quote || cmd[i] == single_quote) && !escaped(cmd, i))
			{
				opened_quote = cmd[i];
				(*new)[j++] = cmd[i];
			}
			else
				on_closed_quotes(cmd, new, i, &j);
		}
		else
		{
			if (cmd[i] == opened_quote)
				opened_quote = 0;
			(*new)[j++] = cmd[i];
		}
		i++;
	}
}

static inline char	*get_cmds_array(char *cmd)
{
	char	*new;
	int		symbols;
	int		i;

	i = 0;
	symbols = 0;
	while (cmd[i])
	{
		if (cmd[i] == l_crnr || cmd[i] == r_crnr || cmd[i] == pipes)
			symbols++;
		i++;
	}
	new = ft_calloc(ft_strlen(cmd) + 1 + symbols * 2, 1);
	if (new == NULL)
	{
		print_err(MSG_ERR_MEM, NULL, 0);
		return (NULL);
	}
	i = 0;
	symbols = 0;
	copy_with_separators(&new, cmd, i, symbols);
	return (new);
}

static inline char	**split_cmd(char *cmd, char **env)
{
	int		i;
	char	**split_cmds;
	char	*tmp;

	i = 0;
	tmp = get_cmds_array(cmd);
	split_cmds = ft_split(tmp, SEPARATOR);
	free(tmp);
	while (split_cmds && split_cmds[i])
	{
		if (*split_cmds[i] != quote && *split_cmds[i] != single_quote)
		{
			if (ft_strchr(split_cmds[i], asterisk))
				tmp = parse_cmd(split_cmds[i], env, asterisk);
			else
				tmp = parse_cmd(split_cmds[i], env, false);
			free(split_cmds[i]);
			split_cmds[i] = tmp;
		}
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
