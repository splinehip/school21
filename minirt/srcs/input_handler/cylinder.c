/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:21:47 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/08 14:20:03 by cflorind         ###   ########.fr       */
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

static inline t_cylinder	*new_pl(t_arg *args)
{
	t_cylinder	*tmp;

	if (args->objs.cy_len)
	{
		tmp = args->objs.cy;
		args->objs.cy = ft_xcalloc(++args->objs.cy_len, sizeof(t_cylinder));
		ft_memcpy(args->objs.cy, tmp,
			(args->objs.cy_len - 1) * sizeof(t_cylinder));
		free(tmp);
		return (&args->objs.cy[args->objs.cy_len - 1]);
	}
	else
	{
		args->objs.cy = ft_xcalloc(++args->objs.cy_len, sizeof(t_cylinder));
		return (args->objs.cy);
	}
}

static inline void	set_point(t_arg *args, char *str)
{
	int			i;
	char		**strs;
	t_cylinder	*cy;

	cy = new_pl(args);
	strs = ft_split(str, ',');
	check_split_res("set_cylinder.point", strs);
	i = 0;
	while (strs[i])
	{
		cy->point[i] = ft_strtod(strs[i], NULL);
		if (errno == ERANGE)
		{
			print_err(MSG_INVALRANGE);
			logger("cylinder.point[%c]: %f, >%s<: %s\n", axis_idx_name(i),
				cy->point[i], strs[i], strerror(errno));
			exit(unsuccess);
		}
		logger("cylinder.point[%c]: %f\n", axis_idx_name(i), cy->point[i]);
		free(strs[i++]);
	}
	free(strs);
}

static inline void	set_norma(t_cylinder *cy, char *str)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ',');
	check_split_res("set_cylinder.norma", strs);
	i = 0;
	while (strs[i])
	{
		cy->norma[i] = ft_strtod(strs[i], NULL);
		if (errno == ERANGE)
		{
			print_err(MSG_INVALRANGE);
			logger("cylinder.norma[%c]: %f, >%s<: %s\n", axis_idx_name(i),
				cy->norma[i], strs[i], strerror(errno));
			exit(unsuccess);
		}
		check_norma_range("cylinder.norma", cy->norma[i], i);
		free(strs[i++]);
	}
	free(strs);
}

static inline void	set_color(t_arg *args, char *str)
{
	int			i;
	char		**strs;
	t_cylinder	*cy;

	cy = &args->objs.cy[args->objs.cy_len - 1];
	strs = ft_split(str, ',');
	check_split_res("set_cylinder.color", strs);
	i = 0;
	while (strs[i])
	{
		cy->color[i] = ft_atoi(strs[i]);
		if (cy->color[i] < RGB_MIN || cy->color[i] > RGB_MAX)
		{
			print_err(MSG_INVALRANGE);
			logger("cylinder.color[%c]: %i is out of range: %i - %i\n",
				axis_idx_name(i), cy->color[i], RGB_MIN, RGB_MAX);
			exit(unsuccess);
		}
		logger("cylinder.color[%c]: %i\n", rgb_idx_name(i), cy->color[i]);
		free(strs[i++]);
	}
	free(strs);
}

void	set_cylinder(t_arg *args, char **strs)
{
	int	i;

	logger("set_cylinder: cylinder number %i\n", args->objs.cy_len + 1);
	i = 0;
	while (strs[i])
		i++;
	if (i != 6)
	{
		print_err(MSG_INVSCENEARG);
		logger("%s: args number: %i, %s", "set_cylinder",
			--i, MSG_INVSCENEARG);
		exit(unsuccess);
	}
	set_point(args, strs[1]);
	set_norma(&args->objs.cy[args->objs.cy_len - 1], strs[2]);
	set_cylinder_dh(&args->objs.cy[args->objs.cy_len - 1], strs[3], strs[4]);
	set_color(args, strs[5]);
}
