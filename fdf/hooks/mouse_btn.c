/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_btn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:11:50 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/23 20:21:20 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static inline int	scale(int btn, t_fdf *vars)
{
	if (btn == 4)
		vars->map_scale += 2;
	if (btn == 5)
		vars->map_scale -= 2;
	display_map(vars);
	return (0);
}

int	mouse_btn(int btn, int x, int y, t_fdf *vars)
{
	t_point			end;
	static t_point	start;

	ft_printf("btn: %i, x: %i, y: %i\n", btn, x, y);
	if (btn == 4 || btn == 5)
		return (scale(btn, vars));
	if (start.x || start.y)
	{
		end.x = x;
		end.y = y;
		end.z = vars->map_max_z;
		end.color = color(0, 100, 100);
		draw_line(vars, start, end);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	start.x = x;
	start.y = y;
	start.z = 0;
	start.color = 0;
	return (0);
}
