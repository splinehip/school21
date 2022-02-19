/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:14:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/19 22:08:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"

#include "bool.h"
#include "key_codes.h"
#include "scene_handler.h"
#include "hooks.h"

static inline void	arrow(int keycode, t_arg *args)
{
	if (keycode == UP)
	{
		args->camera.vpoint.x += 10;
		draw_scene(args);
		mlx_put_image_to_window(args->mlx, args->win, args->img, 0, 0);
	}
	if (keycode == DOWN)
	{
		args->camera.vpoint.x -= 10;
		draw_scene(args);
		mlx_put_image_to_window(args->mlx, args->win, args->img, 0, 0);
	}
	if (keycode == RIGHT)
	{
		args->camera.vpoint.y += 10;
		draw_scene(args);
		mlx_put_image_to_window(args->mlx, args->win, args->img, 0, 0);
	}
	if (keycode == LEFT)
	{
		args->camera.vpoint.y -= 10;
		draw_scene(args);
		mlx_put_image_to_window(args->mlx, args->win, args->img, 0, 0);
	}
}

int	key_press(int keycode, t_arg *args)
{
	printf("KEY_PRESSED: %i\n", keycode);
	if (keycode == CTRL)
		args->cntl = true;
	if (keycode == ESC)
		close_win(args);
	if (keycode == MINUS)
	{
		if (args->camera.fov < 180)
			args->camera.fov += 10;
		draw_scene(args);
		mlx_put_image_to_window(args->mlx, args->win, args->img, 0, 0);
	}
	if (keycode == PLUS)
	{
		if (args->camera.fov > 0)
			args->camera.fov -= 10;
		draw_scene(args);
		mlx_put_image_to_window(args->mlx, args->win, args->img, 0, 0);
	}
	arrow(keycode, args);
	return (0);
}
