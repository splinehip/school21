/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:06:41 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 16:33:02 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "scene_handler.h"

void	plane_intersects(t_arg *args, t_plane *pl, t_vec *ray, t_pxl *pxl)
{
	float	dist;
	float	dot_r_nv;
	t_vec	cam_pl;

	normalise_vect(&pl->vnorma);
	dot_r_nv = vect_dot_product(*ray, pl->vnorma);
	if (dot_r_nv == 0 || fabs(dot_r_nv) < MIN_DIST)
		return ;
	cam_pl = vect_substract(args->origin, pl->vpoint);
	dist = -vect_dot_product(cam_pl, pl->vnorma) / dot_r_nv;
	if (dist < MIN_DIST || dist > MAX_DIST)
		return ;
	pl->vh_point = vect_mult(*ray, dist);
	pl->vh_norma = get_hit_direction(pl, PLANE, *ray);
	if (dist && dist < pxl->dist)
	{
		pxl->type = PLANE;
		pxl->dist = dist;
		ft_memcpy(&pxl->rgb, &pl->color, sizeof(pl->color));
		pxl->vh_norma = pl->vh_norma;
		pxl->vh_point = pl->vh_point;
	}
}
