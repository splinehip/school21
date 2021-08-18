/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:57:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/18 17:05:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	draw(t_fdf *vars, t_point start, t_point end)
{
	int				color;

	color = trgb(0, 125, 125, 125);
	if (vars->line_display_map)
		draw_line(vars, start, end, color);
	else
		draw_point(vars, end.x, end.y, color);
}

static inline void	convert_xyz(int *map, int *converted_map)
{
	converted_map[X] = map[X];
	converted_map[Y] = map[Y];
	converted_map[COLOR] = map[Z];
}

static inline int	point_in_screen(t_fdf *vars, t_point offset, int i)
{
	if (vars->converted_map[i][X] * vars->map_scale + offset.x
		<= vars->screen_size_x
		&& vars->converted_map[i][X] * vars->map_scale + offset.x >= 0
		&& vars->converted_map[i][Y] * vars->map_scale + offset.y
			<= vars->screen_size_y
		&& vars->converted_map[i][Y] * vars->map_scale + offset.y >=0)
		return (1);
	return (0);
}

static inline void	draw_map(t_fdf *vars, t_point offset)
{
	int		i;
	t_point	tmp;
	t_point	end;
	t_point	start;

	i = 0;
	start.x = 0;
	start.y = 0;
	while (vars->converted_map[i] != NULL && vars->map_scale > 0)
	{
		if (point_in_screen(vars, offset, i))
		{
			end.x = vars->converted_map[i][X] * vars->map_scale + offset.x;
			end.y = vars->converted_map[i][Y] * vars->map_scale + offset.y;
			if ((start.x == 0 && start.y == 0)
				|| i % (vars->map_size_x + 1) == 0
				|| (i != 0 && !point_in_screen(vars, offset, i - 1))
				|| (vars->converted_map[i + 1] != NULL
					&& !point_in_screen(vars, offset, i + 1)))
			{
				tmp.x = 0;
				tmp.y = end.y;
				if (i != 0 && !point_in_screen(vars, offset, i - 1))
					draw(vars, tmp, end);
				tmp.x = end.x;
				end.x = vars->screen_size_x;
				if (vars->converted_map[i + 1] != NULL
					&& !point_in_screen(vars, offset, i + 1))
				{
					draw(vars, tmp, end);
					end.x = tmp.x;
				}
				else
				{
					end.x = tmp.x;
					start.x = end.x;
					start.y = end.y;
				}
			}
			draw(vars, start, end);
			start.x = end.x;
			start.y = end.y;
		}
		i++;
	}
}

void	display_map(t_fdf *vars)
{
	int		i;
	t_point	offset;

	ft_bzero(vars->img_addr,
		vars->screen_size_y * vars->screen_size_x * (vars->bits_per_pixel / 8));
	i = 0;
	while (vars->map[i] != NULL)
	{
		convert_xyz(vars->map[i], vars->converted_map[i]);
		i++;
	}
	if (vars->map_scale < 0)
		vars->map_scale = 0;
	offset.x = vars->screen_size_x /2 - (vars->map_size_x * vars->map_scale /2);
	offset.y = vars->screen_size_y /2 - (vars->map_size_y * vars->map_scale /2);
	draw_map(vars, offset);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
