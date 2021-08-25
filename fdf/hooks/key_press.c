/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:14:14 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/25 12:23:48 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static inline void	z_scale(t_fdf *vars, int keycode)
{
	if (keycode == PLUS)
	{
		if (vars->map_z_scale < 0)
			vars->map_z_scale = 0;
		vars->map_z_scale += 1;
	}
	else if (keycode == MINUS)
	{
		if (vars->map_z_scale > 0)
			vars->map_z_scale = 0;
		vars->map_z_scale -= 1;
	}
}

static inline void	map_controls(t_fdf *vars, int keycode)
{
	if (keycode == UP)
		vars->map_scale += 1;
	else if (keycode == DOWN)
		vars->map_scale -= 1;
	else if (vars->ctrl == 0 && keycode == P)
		vars->display_line = 0;
	else if (keycode == L)
		vars->display_line = 1;
	else if (keycode == I)
		vars->iso = 1;
	else if (vars->ctrl && keycode == P)
	{
		vars->ctrl = 0;
		vars->iso = 0;
	}
	z_scale(vars, keycode);
	display_map(vars);
}

int	key_press(int keycode, t_fdf *vars)
{
	ft_printf("KEY_PRESSED: %i\n", keycode);
	if (keycode == CTRL)
		vars->ctrl = 1;
	if (keycode == ESC)
		close_win(vars);
	map_controls(vars, keycode);
	return (0);
}
