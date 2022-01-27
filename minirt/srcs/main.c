/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:49:43 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/27 16:27:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "mlx.h"

#include "libft.h"
#include "bool.h"
#include "msg_err.h"
#include "hooks.h"
#include "logger.h"
#include "minirt.h"

inline void	free_args(t_arg *args)
{
	int	i;

	if (MACOS == false)
	{
		mlx_destroy_image(args->mlx, args->img);
		mlx_destroy_window(args->mlx, args->win);
		mlx_destroy_display(args->mlx);
	}
	free(args->mlx);
	free(args->objs.sh);
	free(args->objs.pl);
	free(args->objs.cy);
	i = 3;
	while (i < 256)
		close(i++);
}

static inline void	init_mlx_args(t_arg *args)
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

static inline void	init_args(t_arg *args)
{
	init_mlx_args(args);
	args->ambient.alr = 0.0;
	args->ambient.color[r] = 0;
	args->ambient.color[g] = 0;
	args->ambient.color[b] = 0;
	args->light.point[x] = 0;
	args->light.point[y] = 0;
	args->light.point[z] = 0;
	args->light.lbr = 0.0;
	args->light.color[r] = 0;
	args->light.color[g] = 0;
	args->light.color[b] = 0;
	args->camera.point[x] = 0;
	args->camera.point[y] = 0;
	args->camera.point[z] = 0;
	args->camera.norma[x] = 0.0;
	args->camera.norma[y] = 0.0;
	args->camera.norma[z] = 0.0;
	args->objs.sh = NULL;
	args->objs.pl = NULL;
	args->objs.cy = NULL;
	args->objs.sh_len = 0;
	args->objs.pl_len = 0;
	args->objs.cy_len = 0;
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (argc != 2)
	{
		write(2, MSG_ERRARG, ft_strlen(MSG_ERRARG));
		logger(LOG_INVALARG);
		exit(unsuccess);
	}
	(void)argv;
	init_args(&args);
	args.mlx = mlx_init();
	mlx_get_screen_size(args.mlx, &args.window_width, &args.window_height);
	logger("mlx_get_screen_size: width: %i, height: %i\n",
		args.window_width, args.window_height);
	args.win = mlx_new_window(args.mlx, args.window_width, args.window_height,
			PROG_NAME);
	args.img = mlx_new_image(args.mlx, args.window_width, args.window_height);
		args.img_addr = mlx_get_data_addr(args.img, &args.bits_per_pixel,
			&args.length, &args.endian);
	hooks_reg(&args);
	mlx_loop(args.mlx);
	free_args(&args);
	exit(success);
}
