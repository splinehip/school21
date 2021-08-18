/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:48:19 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/18 09:55:33 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	free_vars(t_fdf *vars)
{
	int	i;

	i = 0;
	while (vars->map[i] != NULL)
		free(vars->map[i++]);
	free(vars->map);
}

int	main(int argc, char **argv)
{
	t_fdf	vars;

	vars.ctrl = 0;
	vars.map_scale = 10;
	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &vars.screen_size_x, &vars.screen_size_y);
	if (argc == 2)
		argv_handler(argv[1], &vars);
	vars.win = mlx_new_window(vars.mlx, vars.screen_size_x, vars.screen_size_y,
			"FDF Project");
	vars.img = mlx_new_image(vars.mlx, vars.screen_size_x, vars.screen_size_y);
	vars.img_addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.length, &vars.endian);
	display_map(&vars);
	hooks_reg(&vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free_vars(&vars);
	ft_printf("EXIT, bye!\n");
	exit(0);
}
