/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:23:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/29 13:35:47 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "actions_handler.h"
#include "input_handler.h"

int	input_handler(char **cmd, char **env)
{
	int			res;
	t_node		*node;

	if (cmd == NULL || *cmd == NULL)
		return (-1);
	res = check_cmd_sequenses(*cmd);
	if (!res)
		return (2);
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
	return (do_actions(do_actions_build(*cmd, env), env));
}
