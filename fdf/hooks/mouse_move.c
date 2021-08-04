/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:10:34 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/04 15:45:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mouse_move(int x, int y, t_fdf *vars)
{
	int	i;

	i = 10;
	ft_printf("x: %i, y: %i\n", x, y);
	if (vars->ctrl)
	{
		while (i--)
		{
			draw_point(vars, x + 10 - i, y, trgb(0, 255, 255, 255));
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	return (0);
}
