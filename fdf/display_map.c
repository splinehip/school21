/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:57:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/25 14:01:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	convert_xyz(t_fdf *vars, int ix, int iy)
{
	if (vars->map_z_scale)
	{
		if (vars->map[iy][ix][Z] != 0)
		{
			vars->map[iy][ix][Z] += vars->map_z_scale;
			if (vars->map[iy][ix][Z] == 0)
				vars->map[iy][ix][Z] += vars->map_z_scale;
		}
	}
	vars->map[iy][ix][X] = ix * vars->map_scale;
	vars->map[iy][ix][Y] = iy * vars->map_scale;
	if (vars->iso)
		iso(vars, ix, iy);
	if (vars->map[iy][ix][Z] < vars->map_min_z)
		vars->map_min_z = vars->map[iy][ix][Z];
	if (vars->map[iy][ix][Z] > vars->map_max_z)
		vars->map_max_z = vars->map[iy][ix][Z];
}

static inline void	set_offset(t_fdf *vars, t_point *offset)
{
	if (vars->iso)
	{
		offset->x = vars->screen_size_x / 2
			- (vars->map_size_x * vars->map_scale - 300) / 2;
		offset->y = vars->screen_size_y /2
			- vars->map_size_y * vars->map_scale + 150 / 2;
	}
	else
	{
		offset->x = vars->screen_size_x / 2
			- vars->map_size_x * vars->map_scale / 2;
		offset->y = vars->screen_size_y /2
			- vars->map_size_y * vars->map_scale / 2;
	}
}

void	display_map(t_fdf *vars)
{
	t_point	i;
	t_point	offset;

	ft_bzero(vars->img_addr,
		vars->screen_size_y * vars->screen_size_x * (vars->bits_per_pixel / 8));
	if (vars->map_scale == 0)
		vars->map_scale = 1;
	i.y = 0;
	while (vars->map[i.y] != NULL)
	{
		i.x = 0;
		while (vars->map[i.y][i.x] != NULL)
			convert_xyz(vars, i.x++, i.y);
		i.y++;
	}
	set_offset(vars, &offset);
	draw_map(vars, offset);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	vars->map_z_scale = 0;
}
