/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/14 11:33:10 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "input_handler.h"

t_actions	*do_actions_build(char *cmd, char **env)
{
	char		*parsed_cmd_str;
	t_actions	*actions;

	actions = NULL;
	if (cmd == NULL)
		return (actions);
	parsed_cmd_str = parse_cmd(cmd, env);
	free(parsed_cmd_str);
	return (actions);
}
