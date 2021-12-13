/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/13 15:04:51 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "input_handler.h"

t_actions	*do_actions_build(char *cmd, char **env)
{
	t_actions	*actions;

	(void)env;
	actions = NULL;
	if (cmd == NULL)
		return (actions);
	return (actions);
}
