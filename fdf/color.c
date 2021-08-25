/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:09:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/25 15:27:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	get_color(t_color color, int min_z, int max_z, int z)
{
	double	prc;

	if (z > 0 && z < max_z / 2)
	{
		prc = (double)(z / (max_z / 2));
		color.r = (int)((1 - prc) * get_r(GREEN) + prc * get_r(YELOW));
		color.g = (int)((1 - prc) * get_g(GREEN) + prc * get_g(YELOW));
		color.b = (int)((1 - prc) * get_b(GREEN) + prc * get_b(YELOW));
	}
	else if (z > 0 && z > max_z / 2)
	{
		prc = (double)(z - (max_z / 2)) / (max_z - (max_z / 2));
		color.r = (int)((1 - prc) * get_r(YELOW) + prc * get_r(BROWN));
		color.g = (int)((1 - prc) * get_g(YELOW) + prc * get_g(BROWN));
		color.b = (int)((1 - prc) * get_b(YELOW) + prc * get_b(BROWN));
	}
	else if (z <= 0)
	{
		prc = (double)(((z - min_z) * -1) / min_z * -1);
		color.r = (int)((1 - prc) * get_r(BLUE) + prc * get_r(GREEN));
		color.g = (int)((1 - prc) * get_g(BLUE) + prc * get_g(GREEN));
		color.b = (int)((1 - prc) * get_b(BLUE) + prc * get_b(GREEN));
	}
	return (trgb(0, color.r, color.g, color.b));
}

int	color(int map_min_z, int map_max_z, int z)
{
	t_color	color;

	if (z == map_max_z)
		return (BROWN);
	if (z == map_min_z)
		return (BLUE);
	if (z == map_max_z / 2)
		return (GREEN);
	color.r = 0;
	color.g = 0;
	color.b = 0;
	return (get_color(color, map_min_z, map_max_z, z));
}

int	gradient(int len, int step, t_point start, t_point end)
{
	t_color	color;
	double	prc;

	if (start.color == end.color)
		return (end.color);
	if (step == 0)
		return (start.color);
	if (len == 0)
		prc = 1.0;
	else
		prc = (double)step / len;
	color.r = (int)((1 - prc) * get_r(start.color) + prc * get_r(end.color));
	color.g = (int)((1 - prc) * get_g(start.color) + prc * get_g(end.color));
	color.b = (int)((1 - prc) * get_b(start.color) + prc * get_b(end.color));
	return (trgb(0, color.r, color.g, color.b));
}
