/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_btn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:11:50 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/11 14:47:48 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_btn(int btn, int x, int y, t_fdf *vars)
{
	t_point			end;
	static t_point	start;

	ft_printf("btn: %i, x: %i, y: %i\n", btn, x, y);
	if (start.x || start.y)
	{
		end.x = x;
		end.y = y;
		draw_line(start, end, vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	start.x = x;
	start.y = y;
	return (0);
}
