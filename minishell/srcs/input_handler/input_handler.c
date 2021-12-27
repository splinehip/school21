/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:23:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/27 15:36:09 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "bool.h"
#include "actions_handler.h"
#include "input_handler.h"

int	input_handler(char **cmd, char **env)
{
	int			res;
	t_actions	*actions;
	t_node		*node;

	if (cmd == NULL)
		return (0);
	actions = NULL;
	res = check_cmd_sequenses(*cmd);
	if (res)
	{
		*cmd = trim_and_update_cmdstr(cmd);
		if (has_logical_operators(*cmd, 0, 0, 0))
		{
			// printf("\ninput \033[35m%s\033[0m has logical operators\n", *cmd);
			node = extract_node(cmd);
			res = exec_node(node, env);
			if (!node)
				return (res);
			free(node->left);
			free(node->right);
			free(node);
			return (res);
		}
		actions = do_actions_build(*cmd, env);
	}
	return (do_actions(actions, env));
}
