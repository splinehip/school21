/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_escaped.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:58:06 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/12 14:16:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "bool.h"
#include "input_handler.h"

inline int	escaped(char *cmd, int i)
{
	int	j;

	j = i;
	while (j > 0 && cmd[j - 1] == escape)
		j--;
	if ((i - j) % 2 != 0)
		return (true);
	return (false);
}
