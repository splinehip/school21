/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:23:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/26 15:41:49 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "bool.h"
#include "input_handler.h"

static inline int	has_logic_operators(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == ampersand && escaped(cmd, i) == false)
			return (true);
		if (cmd[i] == pipes && escaped(cmd, i) == false
			&& cmd[i + 1] == pipes && escaped(cmd, i + 1) == false)
			return (true);
		if (cmd[i] == open_parenthes && escaped(cmd, i) == false)
			return (true);
		i++;
	}
	return (false);
}

static inline t_actions	*do_actions_build_logic_op(char *cmd, char **env)
{
	(void)cmd;
	(void)env;
	return (NULL);
}

int	input_handler(char *cmd, char **env)
{
	int			check_res;
	t_actions	*actions;

	if (cmd == NULL)
		return (0);
	actions = NULL;
	check_res = check_cmd_sequenses(cmd);
	if (check_res)
	{
		if (has_logic_operators(cmd))
			actions = do_actions_build_logic_op(cmd, env);
		else
			actions = do_actions_build(cmd, env);
	}
	return (do_actions(actions, env));
}
