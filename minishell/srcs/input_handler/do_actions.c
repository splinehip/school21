/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:28:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 14:59:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "builtins.h"
#include "input_handler.h"

int	do_actions(t_actions *actions, char **env)
{
	(void)env;
	if (actions == NULL)
		return (0);
	free(actions->args);
	free(actions);
	return (0);
}
