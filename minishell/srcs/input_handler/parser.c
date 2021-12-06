/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 12:02:48 by cflorind         ###   ########.fr       */
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

t_actions	*parser(char *cmd)
{
	t_actions	*actions;

	(void)cmd;
	actions = NULL;
	return (actions);
}
