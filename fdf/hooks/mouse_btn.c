/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_btn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:11:50 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/04 19:42:17 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	draw_line(int x0, int x1, int y0, int y1, t_fdf *vars)
{
	int	dx;
	int	dy;
	int	err;
	int	derr;
	int	y;
	int	diry;

	dx = x1 - x0;
	dy = y1 - y0;
	err = 0;
	derr = dy + 1;
	y = y0;
	diry = y1 - y0;
	if (diry > 0)
		diry = 1;
	if (diry < 0)
		diry = -1;
	while (x0 != x1)
	{
		draw_point(vars, x0, y, trgb(255, 125, 125, 125));
		err += derr;
		if (err >= dx + 1)
		{
			y += diry;
			err -= dx + 1;
		}
		x0++;
	}
}

int	mouse_btn(int btn, int x, int y, t_fdf *vars)
{
	static int	x0;
	static int	y0;

	ft_printf("btn: %i, x: %i, y: %i\n", btn, x, y);
	if (x0 || y0)
	{
		draw_line(x0, x, y0, y, vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	x0 = x;
	y0 = y;
	return (0);
}
