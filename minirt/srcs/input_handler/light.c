/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:15:27 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/07 14:54:44 by cflorind         ###   ########.fr       */
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

static inline void	check_split_res(char *name, char **strs)
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

static inline void	set_point(t_arg *args, char *str)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ',');
	check_split_res("light.point", strs);
	i = 0;
	while (strs[i])
	{
		args->light.point[i] = ft_strtod(strs[i], NULL);
		if (errno == ERANGE)
		{
			print_err(MSG_INVALRANGE);
			logger("light.point[%c]: %f, >%s<: %s\n", axis_idx_name(i),
				args->light.point[i], str, strerror(errno));
			exit(errno);
		}
		logger("light.point[%c]: %f\n",
			axis_idx_name(i), args->light.point[i]);
		free(strs[i++]);
	}
	free(strs);
}

static inline void	set_lbr(t_arg *args, char *str)
{
	args->light.lbr = ft_strtod(str, NULL);
	if (errno == ERANGE
		|| args->light.lbr < LBR_MIN || args->light.lbr > LBR_MAX)
	{
		print_err(MSG_INVALRANGE);
		if (errno == ERANGE)
			logger("light.lbr: %f, >%s<: %s\n",
				args->light.lbr, str, strerror(errno));
		else
			logger("light.lbr: %f is out of range: %f - %f\n",
				args->light.lbr, LBR_MIN, LBR_MAX);
		exit(errno);
	}
	logger("light.lbr: %f\n", args->light.lbr);
}

static inline void	set_color(t_arg *args, char *str)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ',');
	check_split_res("light.color", strs);
	i = 0;
	while (strs[i])
	{
		args->light.color[i] = ft_atoi(strs[i]);
		if (args->light.color[i] < RGB_MIN || args->light.color[i] > RGB_MAX)
		{
			print_err(MSG_INVALRANGE);
			logger("light.color[%c]: %i is out of range: %i - %i\n",
				axis_idx_name(i), args->light.color[i], RGB_MIN, RGB_MAX);
			exit(unsuccess);
		}
		logger("light.color[%c]: %i\n",
			rgb_idx_name(i), args->light.color[i]);
		free(strs[i++]);
	}
	free(strs);
}

void	set_light(t_arg *args, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (args->light.seted || (i != 3 && i != 4))
	{
		if (args->light.seted)
		{
			print_err(MSG_NOTUNIQ);
			logger("%s: %s", "set_light", MSG_NOTUNIQ);
		}
		if (i != 3 && i != 4)
		{
			print_err(MSG_INVSCENEARG);
			logger("%s: args number: %i, %s", "set_light",
				--i, MSG_INVSCENEARG);
		}
		exit(unsuccess);
	}
	set_point(args, strs[1]);
	set_lbr(args, strs[2]);
	if (i == 4)
		set_color(args, strs[3]);
	args->light.seted = true;
}
