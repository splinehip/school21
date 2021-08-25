/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:48:19 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/25 13:53:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static inline void	free_vars(t_fdf *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while (vars->map[i][j] != NULL)
			free(vars->map[i][j++]);
		free(vars->map[i++]);
	}
	free(vars->map);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

static inline void	init_vars(t_fdf *vars)
{
	vars->ctrl = 0;
	vars->iso = 0;
	vars->map_scale = 10;
	vars->map_z_scale = 1;
	vars->display_line = 1;
	vars->alfa = 0.0;
}

int	main(int argc, char **argv)
{
	t_fdf	vars;

	if (argc == 2 && argv_handler(argv[1], &vars))
	{
		init_vars(&vars);
		vars.mlx = mlx_init();
		mlx_get_screen_size(vars.mlx, &vars.screen_size_x, &vars.screen_size_y);
		vars.win = mlx_new_window(vars.mlx, vars.screen_size_x,
				vars.screen_size_y, "FDF Project");
		vars.img = mlx_new_image(vars.mlx, vars.screen_size_x,
				vars.screen_size_y);
		vars.img_addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
				&vars.length, &vars.endian);
		display_map(&vars);
		hooks_reg(&vars);
		mlx_loop(vars.mlx);
		free_vars(&vars);
	}
	ft_printf("EXIT, bye!\n");
	exit(0);
}
