/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/02 18:11:35 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bool.h"
#include "input_handler.h"

static inline int	parse_string(t_actions *actions, char *str)
{
	(void)str;
	actions->type = expand;
	return (true);
}

t_actions	*parser(char **argv)
{
	int			i;
	t_actions	*actions;

	actions = malloc(sizeof(t_actions));
	if (actions == false)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		if (parse_string(actions, argv[i]) == false)
			return (0);
		i++;
	}
	return (actions);
}
