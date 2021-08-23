/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:57:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/23 16:15:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	convert_xyz(t_fdf *vars, int x, int y, int z)
{
	vars->map[y][x][X] = x;
	vars->map[y][x][Y] = y;
	vars->map[y][x][Z] = z * vars->map_z_scale;
}

void	display_map(t_fdf *vars)
{
	t_point	i;
	t_point	offset;

	ft_bzero(vars->img_addr,
		vars->screen_size_y * vars->screen_size_x * (vars->bits_per_pixel / 8));
	i.y = 0;
	while (vars->map[i.y] != NULL)
	{
		i.x = 0;
		while (vars->map[i.y][i.x] != NULL)
		{
			convert_xyz(vars, i.x, i.y,
				vars->map[i.y][i.x][Z]);
			i.x++;
		}
		i.y++;
	}
	if (vars->map_scale <= 0)
		vars->map_scale = 1;
	if (vars->map_z_scale <=0)
		vars->map_z_scale = 1;
	offset.x = vars->screen_size_x /2 - (vars->map_size_x * vars->map_scale /2);
	offset.y = vars->screen_size_y /2 - (vars->map_size_y * vars->map_scale /2);
	draw_map(vars, offset);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
