/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:52:52 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/25 12:13:31 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	point_in_screen(t_fdf *vars, t_point offset,
	int ix, int iy)
{
	if (vars->map[iy][ix][X] + offset.x
		<= vars->screen_size_x
		&& vars->map[iy][ix][X] + offset.x >= 0
		&& vars->map[iy][ix][Y] + offset.y
			<= vars->screen_size_y
		&& vars->map[iy][ix][Y] + offset.y >=0)
		return (1);
	return (0);
}

static inline void	draw(t_fdf *vars, t_point start, t_point end)
{
	if (vars->display_line)
		draw_line(vars, start, end);
	else
		draw_point(vars, end.x, end.y,
			color(vars->map_min_z, vars->map_max_z, end.z));
}

static inline void	draw_line_x(t_fdf *vars, t_point offset, t_point i)
{
	t_point			end;
	static t_point	start;

	if (point_in_screen(vars, offset, i.x, i.y))
	{
		end.x = vars->map[i.y][i.x][X] + offset.x;
		end.y = vars->map[i.y][i.x][Y] + offset.y;
		end.z = vars->map[i.y][i.x][Z];
		end.color = color(vars->map_min_z, vars->map_max_z, end.z);
		if (i.x == 0
			|| (i.x > 0 && !point_in_screen(vars, offset, i.x - 1, i.y)))
		{
			start.x = end.x;
			start.y = end.y;
			start.z = end.z;
			start.color = end.color;
			draw(vars, start, end);
		}
		else
			draw(vars, start, end);
		start.x = end.x;
		start.y = end.y;
		start.z = end.z;
		start.color = end.color;
	}
}

static inline void	draw_line_y(t_fdf *vars, t_point offset, t_point i)
{
	t_point			end;
	static t_point	start;

	if (point_in_screen(vars, offset, i.x, i.y))
	{
		end.x = vars->map[i.y][i.x][X] + offset.x;
		end.y = vars->map[i.y][i.x][Y] + offset.y;
		end.z = vars->map[i.y][i.x][Z];
		end.color = color(vars->map_min_z, vars->map_max_z, end.z);
		if (i.y == 0
			|| (i.y > 0 && !point_in_screen(vars, offset, i.x, i.y - 1)))
		{
			start.x = end.x;
			start.y = end.y;
			start.z = end.z;
			start.color = end.color;
			draw(vars, start, end);
		}
		else
			draw(vars, start, end);
		start.x = end.x;
		start.y = end.y;
		start.z = end.z;
		start.color = end.color;
	}
}

void	draw_map(t_fdf *vars, t_point offset)
{
	t_point	i;

	i.y = 0;
	while (vars->map[i.y] != NULL)
	{
		i.x = 0;
		while (vars->map[i.y][i.x] != NULL)
		{
			draw_line_x(vars, offset, i);
			i.x++;
		}
		i.y++;
	}
	i.x = 0;
	while (i.x <= vars->map_size_x)
	{
		i.y = 0;
		while (vars->map[i.y] != NULL)
		{
			draw_line_y(vars, offset, i);
			i.y++;
		}
		i.x++;
	}
}
