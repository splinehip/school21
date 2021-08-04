/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:14:14 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/04 15:45:08 by cflorind         ###   ########.fr       */
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
	return (0);
}
