/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:49:43 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 18:11:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "mlx.h"

#include "bool.h"
#include "hooks.h"
#include "minirt.h"

inline void	free_args(t_args *args)
{
	if (MACOS == false)
	{
		mlx_destroy_image(args->mlx, args->img);
		mlx_destroy_window(args->mlx, args->win);
		mlx_destroy_display(args->mlx);
	}
	free(args->mlx);
}

static inline void	init_args(t_args *args)
{
	args->mlx = NULL;
	args->win = NULL;
	args->img = NULL;
	args->img_addr = NULL;
	args->bits_per_pixel = 0;
	args->length = 0;
	args->endian = 0;
	args->window_width = 0;
	args->window_height = 0;
	args->cntl = false;
}

int	main(int argc, char **argv)
{
	t_args	args;

	(void)argc;
	(void)argv;
	init_args(&args);
	args.mlx = mlx_init();
	mlx_get_screen_size(args.mlx, &args.window_width, &args.window_height);
	printf("Hello from miniRT: screen szie is x: %i, y: %i\n",
		args.window_width, args.window_height);
	args.win = mlx_new_window(args.mlx, args.window_width, args.window_height,
			PROG_NAME);
	args.img = mlx_new_image(args.mlx, args.window_width, args.window_height);
		args.img_addr = mlx_get_data_addr(args.img, &args.bits_per_pixel,
			&args.length, &args.endian);
	hooks_reg(&args);
	mlx_loop(args.mlx);
	free_args(&args);
	return (0);
}
