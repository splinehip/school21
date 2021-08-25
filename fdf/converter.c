/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:20:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/25 11:00:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_fdf *vars, int ix, int iy, double alfa)
{
	int	current_y;

	current_y = vars->map[iy][ix][Y];
	vars->map[iy][ix][Y] = current_y * cos(alfa)
		+ vars->map[iy][ix][Z] * sin(alfa);
	vars->map[iy][ix][Z] = -current_y * sin(alfa)
		+ vars->map[iy][ix][Z] * cos(alfa);
}

void	rotate_y(t_fdf *vars, int ix, int iy, double alfa)
{
	int	current_x;

	current_x = vars->map[iy][ix][X];
	vars->map[iy][ix][X] = current_x * cos(alfa)
		+ vars->map[iy][ix][Z] * sin(alfa);
	vars->map[iy][ix][Z] = -current_x * sin(alfa)
		+ vars->map[iy][ix][Z] * cos(alfa);
}

void	rotate_z(t_fdf *vars, int ix, int iy, double alfa)
{
	int	current_x;
	int	current_y;

	current_x = vars->map[iy][ix][X];
	current_y = vars->map[iy][ix][Y];
	vars->map[iy][ix][X] = current_x * cos(alfa) - current_y * sin(alfa);
	vars->map[iy][ix][Y] = current_x * sin(alfa) + current_y * cos(alfa);
}

void	iso(t_fdf *vars, int ix, int iy)
{
	int	current_x;
	int	current_y;

	current_x = vars->map[iy][ix][X];
	current_y = vars->map[iy][ix][Y];
	vars->map[iy][ix][X] = (current_x - current_y) * cos(0.523599);
	vars->map[iy][ix][Y] = -vars->map[iy][ix][Z]
		+ (current_x + current_y) * sin(0.523599);
}
