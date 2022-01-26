/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:49:43 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 12:11:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "mlx.h"

#include "minirt.h"

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	void	*mlx;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	mlx_get_screen_size(mlx, &x, &y);
	printf("Hello from miniRT: screen szie is x: %i, y: %i\n", x, y);
	free(mlx);
	return (0);
}
