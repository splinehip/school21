/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:48:19 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/04 15:44:11 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	vars;

	(void)argc;
	(void)argv;
	vars.ctrl = 0;
	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &(vars.x_size), &(vars.y_size));
	vars.win = mlx_new_window(vars.mlx, vars.x_size, vars.y_size,
			"FDF Project");
	vars.img = mlx_new_image(vars.mlx, vars.x_size, vars.y_size);
	vars.img_addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.length, &vars.endian);
	hooks_reg(&vars);
	mlx_loop(vars.mlx);
	ft_printf("EXIT, bye!\n");
	exit(0);
}
