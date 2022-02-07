/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:10:53 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/07 12:54:33 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "libft.h"
#include "bool.h"
#include "msg_err.h"
#include "logger.h"
#include "input_handler.h"

static inline void	set_alr(t_arg *args, char *str)
{
	args->ambient.alr = ft_strtod(str, NULL);
	if (errno == ERANGE
		|| args->ambient.alr < ALR_MIN || args->ambient.alr > ALR_MAX)
	{
		print_err(MSG_INVALRANGE);
		if (errno == ERANGE)
			logger("ambient.alr: %f, >%s<: %s\n",
				args->ambient.alr, str, strerror(errno));
		else
			logger("ambient.alr: %f is out of range: %f - %f\n",
				args->ambient.alr, ALR_MIN, ALR_MAX);
		exit(errno);
	}
	logger("ambient.alr: %f\n", args->ambient.alr);
}

static inline void	check_split_res(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		i++;
	if (strs == NULL || i > 3)
	{
		print_err(MSG_RESNULL);
		if (strs == NULL)
			logger("ambient.color: ft_split returned NULL\n");
		else
			logger("ambient.color: ft_split returned more than 3 elements\n");
		exit(unsuccess);
	}
}

static inline void	check_range(t_arg *args, int i)
{
	if (args->ambient.color[i] < RGB_MIN
		|| args->ambient.color[i] > RGB_MAX)
	{
		print_err(MSG_INVALRANGE);
		logger("ambient.color[%c]: %i is out of range: %i - %i\n",
			rgb_idx_name(i), args->ambient.color[i], RGB_MIN, RGB_MAX);
		exit(unsuccess);
	}
}

static inline void	set_color(t_arg *args, char *str)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ',');
	check_split_res(strs);
	i = 0;
	while (strs[i])
	{
		args->ambient.color[i] = ft_atoi(strs[i]);
		check_range(args, i);
		logger("ambient.color[%c]: %i\n",
			rgb_idx_name(i), args->ambient.color[i]);
		free(strs[i++]);
	}
	free(strs);
}

void	set_ambient(t_arg *args, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (args->ambient.seted || i != 3)
	{
		if (args->ambient.seted)
		{
			print_err(MSG_NOTUNIQ);
			logger("%s: %s", "set_ambient", MSG_NOTUNIQ);
		}
		if (i != 3)
		{
			print_err(MSG_INVSCENEARG);
			logger("%s: args number: %i, %s", "set_ambient",
				--i, MSG_INVSCENEARG);
		}
		exit(unsuccess);
	}
	set_alr(args, strs[1]);
	set_color(args, strs[2]);
	args->ambient.seted = true;
}
