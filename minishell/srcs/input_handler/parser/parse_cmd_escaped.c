/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_escaped.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:58:06 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/12 19:58:02 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "bool.h"
#include "input_handler.h"

inline int	escaped(char *cmd, int i)
{
	int	j;

	if (i-- == 0)
		return (false);
	j = 0;
	while (i >= 0)
	{
		if (cmd[i] != escape)
			break ;
		j++;
		i--;
	}
	if (j % 2 != 0)
		return (true);
	return (false);
}
