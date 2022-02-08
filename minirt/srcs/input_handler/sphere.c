/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:19:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/08 13:34:18 by cflorind         ###   ########.fr       */
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

static inline t_sphere	*new_sp(t_arg *args)
{
	t_sphere	*tmp;

	if (args->objs.sp_len)
	{
		tmp = args->objs.sp;
		args->objs.sp = ft_xcalloc(++args->objs.sp_len, sizeof(t_sphere));
		ft_memcpy(args->objs.sp, tmp,
			(args->objs.sp_len - 1) * sizeof(t_sphere));
		free(tmp);
		return (&args->objs.sp[args->objs.sp_len - 1]);
	}
	else
	{
		args->objs.sp = ft_xcalloc(++args->objs.sp_len, sizeof(t_sphere));
		return (args->objs.sp);
	}
}

static inline void	set_center(t_arg *args, char *str)
{
	int			i;
	char		**strs;
	t_sphere	*sp;

	sp = new_sp(args);
	strs = ft_split(str, ',');
	check_split_res("set_sphere.center", strs);
	i = 0;
	while (strs[i])
	{
		sp->center[i] = ft_strtod(strs[i], NULL);
		if (errno == ERANGE)
		{
			print_err(MSG_INVALRANGE);
			logger("sphere.center[%c]: %f, >%s<: %s\n", axis_idx_name(i),
				sp->center[i], strs[i], strerror(errno));
			exit(unsuccess);
		}
		logger("sphere.center[%c]: %f\n", axis_idx_name(i), sp->center[i]);
		free(strs[i++]);
	}
	free(strs);
}

static inline void	set_color(t_arg *args, char *str)
{
	int			i;
	char		**strs;
	t_sphere	*sp;

	sp = &args->objs.sp[args->objs.sp_len - 1];
	strs = ft_split(str, ',');
	check_split_res("set_sphere.color", strs);
	i = 0;
	while (strs[i])
	{
		sp->color[i] = ft_atoi(strs[i]);
		if (sp->color[i] < RGB_MIN || sp->color[i] > RGB_MAX)
		{
			print_err(MSG_INVALRANGE);
			logger("sphere.color[%c]: %i is out of range: %i - %i\n",
				axis_idx_name(i), sp->color[i], RGB_MIN, RGB_MAX);
			exit(unsuccess);
		}
		logger("sphere.color[%c]: %i\n", rgb_idx_name(i), sp->color[i]);
		free(strs[i++]);
	}
	free(strs);
}

void	set_sphere(t_arg *args, char **strs)
{
	int	i;

	logger("set_sphere: sphere number %i\n", args->objs.sp_len + 1);
	i = 0;
	while (strs[i])
		i++;
	if (i != 4)
	{
		print_err(MSG_INVSCENEARG);
		logger("%s: args number: %i, %s", "set_sphere",
			--i, MSG_INVSCENEARG);
		exit(unsuccess);
	}
	set_center(args, strs[1]);
	args->objs.sp[args->objs.sp_len - 1].d = ft_strtod(strs[2], NULL);
	if (errno == ERANGE)
	{
		print_err(MSG_INVALRANGE);
		logger("sphere.d: %f, >%s<: %s\n",
			args->objs.sp[args->objs.sp_len - 1].d, strs[i], strerror(errno));
		exit(unsuccess);
	}
	logger("sphere.d: %f\n", args->objs.sp[args->objs.sp_len - 1].d);
	set_color(args, strs[3]);
}
