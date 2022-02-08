/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_split_res.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:17:46 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/08 13:27:48 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bool.h"
#include "msg_err.h"
#include "logger.h"
#include "input_handler.h"

inline void	check_norma_range(char *name, float a, int i)
{
	if (a < NORMA_MIN || a > NORMA_MAX)
	{
		print_err(MSG_INVALRANGE);
		logger("%s[%c]: %f is out of range: %f - %f\n",
			name, axis_idx_name(i), a, NORMA_MIN, NORMA_MAX);
		exit(unsuccess);
	}
	logger("%s[%c]: %f\n", name, axis_idx_name(i), a);
}

inline void	check_split_res(char *name, char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		i++;
	if (strs == NULL || i != 3)
	{
		print_err(MSG_RESNULL);
		if (strs == NULL)
			logger("%s: ft_split returned NULL\n", name);
		else
			logger("%s: ft_split returned more or less 3 elements\n", name);
		exit(unsuccess);
	}
}
