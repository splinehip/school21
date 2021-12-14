/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:28:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/12 17:00:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "builtins.h"
#include "input_handler.h"

int	do_actions(t_actions *actions, char **env)
{
	int	res;

	(void)env;
	res = 0;
	if (actions == NULL)
		return (1);
	if (actions->type == exit_built)
	{
		res = exit_built;
		actions->args = NULL;
	}
	free(actions->args);
	free(actions);
	return (res);
}
