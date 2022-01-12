/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:23:47 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/12 16:37:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

#include "libft.h"
#include "bool.h"
#include "mesages.h"
#include "error_msgs.h"
#include "actions_handler.h"
#include "input_handler.h"
#include "minishell.h"

static int	event(void)
{
	return (0);
}

static inline void	do_update_cmd(char **cmd)
{
	char	*tmp;
	char	*line;

	set_signals(3, 0);
	rl_event_hook = event;
	line = readline(MSG_RL_SUBINPUT);
	if (line != NULL)
	{
		tmp = *cmd;
		*cmd = ft_strjoinchr(*cmd, space);
		free(tmp);
		tmp = *cmd;
		*cmd = ft_strjoin(*cmd, line);
		free(tmp);
		free(line);
	}
	set_signals(0, 1);
}

static inline int	do_append_cmd(char **cmd)
{
	char	*tmp;

	if (cmd == NULL || *cmd == NULL)
		return (unsuccess);
	tmp = *cmd;
	*cmd = ft_strtrim(*cmd, " \t\v\n\r");
	free(tmp);
	if (*cmd == NULL)
		return (unsuccess);
	if (**cmd == pipes)
	{
		print_err(MSG_ERR_SYNATX, NULL, false);
		return (unsuccess);
	}
	if ((*cmd)[ft_strlen(*cmd) - 1] == pipes)
		do_update_cmd(cmd);
	if (*cmd)
		return (success);
	return (unsuccess);
}

static inline void	init(t_actions *actions)
{
	actions->len = 0;
	actions->pipes.len = 0;
	actions->pipes.item = NULL;
	actions->item = NULL;
}

int	input_handler(char **cmd, char ***env)
{
	int			res;
	t_node		*node;
	t_actions	actions;

	if (do_append_cmd(cmd) == unsuccess)
		return (-1);
	res = check_cmd_sequenses(*cmd);
	if (!res)
		return (2);
	init(&actions);
	*cmd = trim_and_update_cmdstr(cmd);
	if (has_logical_operators(*cmd, 0, 0, 0))
	{
		node = extract_node(cmd);
		res = exec_node(node, env);
		if (!node)
			return (res);
		free(node->left);
		free(node->right);
		free(node);
		return (res);
	}
	return (do_actions(do_actions_build(&actions, *cmd, env), env));
}
