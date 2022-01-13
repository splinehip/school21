/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/13 19:28:46 by lbaela           ###   ########.fr       */
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

static inline void	copy_with_separators(char **new, char *cmd, int i, int j)
{
	char	opened_quote;

	opened_quote = 0;
	while (cmd[i])
	{
		if (!opened_quote)
		{
			if (i && (cmd[i] == r_crnr || cmd[i] == l_crnr)
				&& cmd[i] != cmd[i - 1])
				(*new)[j++] = SEPARATOR;
			if ((cmd[i] == quote || cmd[i] == single_quote) && !escaped(cmd, i))
				opened_quote = cmd[i];
			if (cmd[i] == space && !escaped(cmd, i))
				(*new)[j++] = SEPARATOR;
			else
				(*new)[j++] = cmd[i];
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

static inline int	count_corners(char *cmd)
{
	int	i;

	i = 0;
	while (*cmd)
	{
		if (*cmd == l_crnr || *cmd == r_crnr)
			i++;
		cmd++;
	}
	return (i);
}

static inline char	*get_cmds_array(char *cmd)
{
	char	*new;
	int		corners;
	int		i;
	int		j;

	i = 0;
	j = 0;
	corners = count_corners(cmd);
	new = ft_calloc(ft_strlen(cmd) + 1 + corners * 2, 1);
	if (new == NULL)
	{
		print_err(MSG_ERR_MEM, NULL, 0);
		return (NULL);
	}
	copy_with_separators(&new, cmd, i, j);
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
		printf("%d\t %s\n", i, split_cmds[i]);
		if (ft_strchr(split_cmds[i], asterisk)
			&& (*split_cmds[i] != quote && *split_cmds[i] != single_quote))
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
