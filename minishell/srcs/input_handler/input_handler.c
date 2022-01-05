/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:23:47 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/05 15:34:10 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "error_msgs.h"
#include "actions_handler.h"
#include "input_handler.h"

static inline void	init(t_actions *actions)
{
	actions->len = 0;
	actions->pipes.len = 0;
	actions->pipes.item = NULL;
	actions->item = NULL;
}

int	input_handler(char **cmd, char **env)
{
	int			res;
	t_node		*node;
	t_actions	actions;

	if (cmd == NULL || *cmd == NULL)
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
