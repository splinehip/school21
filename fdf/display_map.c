/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:57:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/24 13:41:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	convert_xyz(t_fdf *vars, int ix, int iy)
{
	if (vars->map_z_scale)
		if (vars->map[iy][ix][Z] != 0)
			vars->map[iy][ix][Z] += vars->map_z_scale;
	vars->map[iy][ix][X] = ix;
	vars->map[iy][ix][Y] = iy;
}

void	display_map(t_fdf *vars)
{
	t_point	i;
	t_point	offset;

	ft_bzero(vars->img_addr,
		vars->screen_size_y * vars->screen_size_x * (vars->bits_per_pixel / 8));
	if (vars->map_scale <= 0)
		vars->map_scale = 1;
	i.y = 0;
	while (vars->map[i.y] != NULL)
	{
		i.x = 0;
		while (vars->map[i.y][i.x] != NULL)
		{
			convert_xyz(vars, i.x, i.y);
			i.x++;
		}
		i.y++;
	}
	offset.x = vars->screen_size_x /2 - (vars->map_size_x * vars->map_scale /2);
	offset.y = vars->screen_size_y /2 - (vars->map_size_y * vars->map_scale /2);
	draw_map(vars, offset);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	vars->map_z_scale = 0;
}
