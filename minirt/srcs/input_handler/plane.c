/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:21:02 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/08 14:21:58 by cflorind         ###   ########.fr       */
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

static inline t_plane	*new_pl(t_arg *args)
{
	t_plane	*tmp;

	if (args->objs.pl_len)
	{
		tmp = args->objs.pl;
		args->objs.pl = ft_xcalloc(++args->objs.pl_len, sizeof(t_plane));
		ft_memcpy(args->objs.pl, tmp,
			(args->objs.pl_len - 1) * sizeof(t_plane));
		free(tmp);
		return (&args->objs.pl[args->objs.pl_len - 1]);
	}
	else
	{
		args->objs.pl = ft_xcalloc(++args->objs.pl_len, sizeof(t_plane));
		return (args->objs.pl);
	}
}

static inline void	set_point(t_arg *args, char *str)
{
	int		i;
	char	**strs;
	t_plane	*pl;

	pl = new_pl(args);
	strs = ft_split(str, ',');
	check_split_res("set_plane.point", strs);
	i = 0;
	while (strs[i])
	{
		pl->point[i] = ft_strtod(strs[i], NULL);
		if (errno == ERANGE)
		{
			print_err(MSG_INVALRANGE);
			logger("plane.point[%c]: %f, >%s<: %s\n", axis_idx_name(i),
				pl->point[i], strs[i], strerror(errno));
			exit(unsuccess);
		}
		logger("plane.point[%c]: %f\n", axis_idx_name(i), pl->point[i]);
		free(strs[i++]);
	}
	free(strs);
}

static inline void	set_color(t_arg *args, char *str)
{
	int		i;
	char	**strs;
	t_plane	*pl;

	pl = &args->objs.pl[args->objs.pl_len - 1];
	strs = ft_split(str, ',');
	check_split_res("set_plane.color", strs);
	i = 0;
	while (strs[i])
	{
		pl->color[i] = ft_atoi(strs[i]);
		if (pl->color[i] < RGB_MIN || pl->color[i] > RGB_MAX)
		{
			print_err(MSG_INVALRANGE);
			logger("plane.color[%c]: %i is out of range: %i - %i\n",
				axis_idx_name(i), pl->color[i], RGB_MIN, RGB_MAX);
			exit(unsuccess);
		}
		logger("plane.color[%c]: %i\n", rgb_idx_name(i), pl->color[i]);
		free(strs[i++]);
	}
	free(strs);
}

static inline void	set_norma(t_plane *pl, char *str)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ',');
	check_split_res("set_plane.norma", strs);
	i = 0;
	while (strs[i])
	{
		pl->norma[i] = ft_strtod(strs[i], NULL);
		if (errno == ERANGE)
		{
			print_err(MSG_INVALRANGE);
			logger("plane.norma[%c]: %f, >%s<: %s\n", axis_idx_name(i),
				pl->norma[i], strs[i], strerror(errno));
			exit(unsuccess);
		}
		check_norma_range("plane.norma", pl->norma[i], i);
		free(strs[i++]);
	}
	free(strs);
}

void	set_plane(t_arg *args, char **strs)
{
	int	i;

	logger("set_plane: plane number %i\n", args->objs.pl_len + 1);
	i = 0;
	while (strs[i])
		i++;
	if (i != 4)
	{
		print_err(MSG_INVSCENEARG);
		logger("%s: args number: %i, %s", "set_plane",
			--i, MSG_INVSCENEARG);
		exit(unsuccess);
	}
	set_point(args, strs[1]);
	set_norma(&args->objs.pl[args->objs.pl_len - 1], strs[2]);
	set_color(args, strs[3]);
}
