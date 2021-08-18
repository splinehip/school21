/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:57:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/17 22:46:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_map(t_fdf *vars)
{
	int	i;
	int	x_offset;
	int	y_offset;

	ft_bzero(vars->img_addr,
		vars->screen_size_y * vars->screen_size_x * (vars->bits_per_pixel / 8));
	if (vars->map_scale < 0)
		vars->map_scale = 0;
	i = 0;
	x_offset = vars->screen_size_x /2 - (vars->map_size_x * vars->map_scale /2);
	y_offset = vars->screen_size_y /2 - (vars->map_size_y * vars->map_scale /2);
	while (vars->map[i] != NULL && vars->map_scale > 0)
	{
		if (vars->map[i][X] * vars->map_scale + x_offset <= vars->screen_size_x
			&& vars->map[i][X] * vars->map_scale + x_offset >= 0
			&& vars->map[i][Y] * vars->map_scale + y_offset
				<= vars->screen_size_y
			&& vars->map[i][Y] * vars->map_scale + y_offset >=0)
			draw_point(vars, vars->map[i][X] * vars->map_scale + x_offset,
				vars->map[i][Y] * vars->map_scale + y_offset,
				trgb(0, 125, 125, 125));
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
