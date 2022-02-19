/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:43:45 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/18 11:54:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "scene_handler.h"

void	rotate_x(t_arg *args, double alfa)
{
	int	current_y;

	current_y = args->camera.vpoint.y;
	args->camera.vpoint.y = current_y * cos(alfa)
		+ args->camera.vpoint.z * sin(alfa);
	args->camera.vpoint.z = -current_y * sin(alfa)
		+ args->camera.vpoint.z * cos(alfa);
}

void	rotate_y(t_arg *args, double alfa)
{
	int	current_x;

	current_x = args->camera.vpoint.x;
	args->camera.vpoint.x = current_x * cos(alfa)
		+ args->camera.vpoint.z * sin(alfa);
	args->camera.vpoint.z = -current_x * sin(alfa)
		+ args->camera.vpoint.z * cos(alfa);
}

void	rotate_z(t_arg *args, double alfa)
{
	int	current_x;
	int	current_y;

	current_x = args->camera.vpoint.x;
	current_y = args->camera.vpoint.y;
	args->camera.vpoint.x = current_x * cos(alfa) - current_y * sin(alfa);
	args->camera.vpoint.y = current_x * sin(alfa) + current_y * cos(alfa);
}

void	skeep_cam_to_def(t_arg *args)
{
	args->camera.vpoint.x = args->camera.point[x];
	args->camera.vpoint.y = args->camera.point[y];
	args->camera.vpoint.z = args->camera.point[z];
}
