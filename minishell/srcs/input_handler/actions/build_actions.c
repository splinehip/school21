/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/17 21:39:09 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "input_handler.h"

t_actions	*do_actions_build(char *cmd, char **env)
{
	char		*parsed_cmd_str;
	t_actions	*actions;

	actions = malloc(sizeof(t_actions));
	parsed_cmd_str = parse_cmd(cmd, env);
	if (cmd == NULL || actions == NULL || parsed_cmd_str == NULL)
	{
		free(actions);
		free(parsed_cmd_str);
		return (NULL);
	}
	if (ft_strncmp(parsed_cmd_str, "exit", 4) == 0)
		actions->type = exit_built;
	else
	{
		free(actions);
		actions = NULL;
	}
	free(parsed_cmd_str);
	return (actions);
}
