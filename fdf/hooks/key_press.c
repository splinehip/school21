/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:14:14 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/17 19:28:11 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_press(int keycode, t_fdf *vars)
{
	ft_printf("KEY_PRESSED: %i\n", keycode);
	if (vars->ctrl)
	{
		ft_printf("CTRL + KEY pressed, KEY: %i\n", keycode);
		vars->ctrl = 0;
	}
	if (keycode == CTRL)
		vars->ctrl = 1;
	if (keycode == ESC)
		close_win(vars);
	if (keycode == UP)
	{
		vars->map_scale += 2;
		display_map(vars);
	}
	if (keycode == DOWN)
	{
		vars->map_scale -= 2;
		display_map(vars);
	}
	return (0);
}
