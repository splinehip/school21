/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:09:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/23 20:40:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color(int map_min_z, int map_max_z, int z)
{
	int		red;
	int		green;
	int		blue;
	int		range;
	double	prc;

	range = map_max_z - map_min_z;
	if (range == 0)
		range = 1;
	prc = (double)(z - map_min_z) / range;
	red = (int)((1 - prc) * 0 + prc * 82);
	green = (int)((1 - prc) * 255 + prc * 54);
	blue = (int)((1 - prc) * 0 + prc * 27);
	return (trgb(0, red, green, blue));
}

int	gradient(int len, int step, t_point start, t_point end)
{
	int		red;
	int		green;
	int		blue;
	double	prc;

	if (start.color == end.color)
		return (end.color);
	if (step == 0)
		return (start.color);
	if (len == 0)
		prc = 1.0;
	else
		prc = (double)step / len;
	red = (int)((1 - prc) * get_r(start.color) + prc * get_r(end.color));
	green = (int)((1 - prc) * get_g(start.color) + prc * get_g(end.color));
	blue = (int)((1 - prc) * get_b(start.color) + prc * get_b(end.color));
	return (trgb(0, red, green, blue));
}
