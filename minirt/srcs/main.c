/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:49:43 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 15:51:51 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "mlx.h"

#include "minirt.h"

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	mlx_get_screen_size(mlx, &x, &y);
	printf("Hello from miniRT: screen szie is x: %i, y: %i\n", x, y);
	win = mlx_new_window(mlx, x, y, "miniRT Project");
	sleep(3);
	mlx_destroy_window(mlx, win);
	free(mlx);
	return (0);
}
