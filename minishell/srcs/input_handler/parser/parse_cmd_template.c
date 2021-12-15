/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_template.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:36:13 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/14 17:21:13 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline int	quoted(char *cmd, t_extract *args)
{
	int	i;

	args->start = args->pchar - cmd - 1;
	args->end = args->pchar - cmd + 1;
	i = 0;
	if (args->prev_end != 0)
		i = args->prev_end + 1;
	if (cmd[args->prev_end] == quote || cmd[args->prev_end] == single_quote)
		i++;
	return (unsucsses);
}

inline int	get_template_border(char *cmd, t_extract *args)
{
	if (quoted(cmd, args))
		return (unsucsses);
	args->start = args->pchar - cmd - 1;
	args->end = args->pchar - cmd + 1;
	while (cmd[args->start] != space && args->start - 1 >= 0)
	{
		if (cmd[args->start] == quote || cmd[args->start] == single_quote)
		{
			if (escaped(cmd, args->start) == false)
			{
				args->start++;
				while (cmd[args->start] != space && args->start - 1 >= 0)
				{
					/* code */
				}
			}
		}
		args->start--;
	}
	while (cmd[args->end] != space)
		args->end++;
	return (unsucsses);
}
