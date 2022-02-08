/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:18:19 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/08 14:24:22 by cflorind         ###   ########.fr       */
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

static inline void	exit_fatal(t_arg *args, int norma, int i, char *str)
{
	print_err(MSG_INVALRANGE);
	if (norma)
		logger("%s[%c]: %f, >%s<: %s\n", "color.norma", axis_idx_name(i),
			args->camera.norma[i], str, strerror(errno));
	else
		logger("%s[%c]: %f, >%s<: %s\n", "color.point", axis_idx_name(i),
			args->camera.point[i], str, strerror(errno));
	exit(errno);
}

static inline void	free_strs(char ***strs)
{
	int	i;

	i = 0;
	while ((*strs)[i])
		free((*strs)[i++]);
	free(*strs);
}

static inline void	set_point(t_arg *args, char *str, int norma)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ',');
	check_split_res("camera.color", strs);
	i = 0;
	while (strs[i])
	{
		if (norma)
			args->camera.norma[i] = ft_strtod(strs[i], NULL);
		else
			args->camera.point[i] = ft_strtod(strs[i], NULL);
		if (errno == ERANGE)
			exit_fatal(args, norma, i, strs[i]);
		if (norma)
			check_norma_range("camera.norma", args->camera.norma[i], i);
		else
			logger("camera.point[%c]: %f\n",
				axis_idx_name(i), args->camera.point[i]);
		i++;
	}
	free_strs(&strs);
}

static inline void	set_fov(t_arg *args, char *str)
{
	args->camera.fov = ft_atoi(str);
	if (args->camera.fov < FOV_MIN || args->camera.fov > FOV_MAX)
	{
		print_err(MSG_INVALRANGE);
		logger("camera.fov: %i is out of range: %i - %i\n",
			args->camera.fov, FOV_MIN, FOV_MAX);
		exit(unsuccess);
	}
	logger("camera.fov: %i\n", args->camera.fov);
}

void	set_camera(t_arg *args, char **strs)
{
	int	i;

	logger("set_camera:\n");
	i = 0;
	while (strs[i])
		i++;
	if (args->camera.seted || i != 4)
	{
		if (args->camera.seted)
		{
			print_err(MSG_NOTUNIQ);
			logger("%s: %s", "set_camera", MSG_NOTUNIQ);
		}
		if (i != 4)
		{
			print_err(MSG_INVSCENEARG);
			logger("%s: args number: %i, %s", "set_camera",
				--i, MSG_INVSCENEARG);
		}
		exit(unsuccess);
	}
	set_point(args, strs[1], false);
	set_point(args, strs[2], true);
	set_fov(args, strs[3]);
	args->camera.seted = true;
}
