/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/12 16:14:14 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

t_actions	*parse_cmd(char *cmd, char **env)
{
	t_actions	*actions;

	actions = NULL;
	cmd = do_parse(cmd, env);
	if (cmd == NULL)
	{
		ft_printf("Parse cmd error.\n");
		return (actions);
	}
	ft_printf("EXPANDED CMD: >%s<\n", cmd);
	free(cmd);
	return (actions);
}
