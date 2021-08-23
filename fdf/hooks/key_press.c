/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:14:14 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/23 20:23:48 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static inline void	map_controls(t_fdf *vars, int keycode)
{
	if (keycode == UP)
		vars->map_scale += 2;
	else if (keycode == DOWN)
		vars->map_scale -= 2;
	else if (keycode == P)
		vars->display_line = 0;
	else if (keycode == L)
		vars->display_line = 1;
	else if (keycode == PLUS)
		vars->map_z_scale += 2;
	else if (keycode == MINUS)
		vars->map_z_scale -= 2;
	display_map(vars);
}

int	key_press(int keycode, t_fdf *vars)
{
	ft_printf("KEY_PRESSED: %i\n", keycode);
	if (vars->ctrl)
		vars->ctrl = 0;
	if (keycode == CTRL)
		vars->ctrl = 1;
	if (keycode == ESC)
		close_win(vars);
	map_controls(vars, keycode);
	return (0);
}
