/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:48:19 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/17 18:16:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	free_vars(t_fdf *vars)
{
	int	i;

	i = 0;
	while (vars->map[i] != NULL)
	{
		ft_printf("x: %i, y: %i, z: %i\n",
			vars->map[i][0], vars->map[i][1], vars->map[i][2]);
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

int	main(int argc, char **argv)
{
	t_fdf	vars;

	vars.ctrl = 0;
	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &(vars.x_size), &(vars.y_size));
	if (argc == 2)
		argv_handler(argv[1], &vars);
	vars.win = mlx_new_window(vars.mlx, vars.x_size, vars.y_size,
			"FDF Project");
	vars.img = mlx_new_image(vars.mlx, vars.x_size, vars.y_size);
	vars.img_addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.length, &vars.endian);
	hooks_reg(&vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free_vars(&vars);
	ft_printf("MAP_SZIE_X: %i\nMAP_SIZE_Y: %i\nMIN_Z: %i\nMAX_Z: %i\n",
		vars.map_size_x, vars.map_size_y, vars.map_min_z, vars.map_max_z);
	ft_printf("EXIT, bye!\n");
	exit(0);
}
