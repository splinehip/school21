/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:54:01 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 17:31:58 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "bool.h"
#include "scene_handler.h"

static inline float	find_dists(t_sphere *sp, t_vec *ray, t_qec qec)
{
	float	dist;

	qec.discr = qec.b * qec.b - (4 * qec.a * qec.c);
	if (qec.discr < 0.0)
		return (0);
	qec.root_1 = (-qec.b - sqrt(qec.discr)) / (2 * qec.a);
	qec.root_2 = (-qec.b + sqrt(qec.discr)) / (2 * qec.a);
	sp->inside = true;
	if (qec.root_1 > MIN_DIST || qec.root_2 > MIN_DIST)
	{
		if (qec.root_1 > MIN_DIST && qec.root_2 > MIN_DIST)
		{
			sp->inside = false;
			dist = fmin(qec.root_1, qec.root_2);
		}
		else if (qec.root_1 > MIN_DIST)
			dist = qec.root_1;
		else
			dist = qec.root_2;
		sp->vh_point = vect_mult(*ray, dist);
		sp->vh_norma = get_hit_direction(sp, SPHERE, *ray);
		normalise_vect(&sp->vh_norma);
		return (dist);
	}
	return (0);
}

void	sphere_intersects(t_arg *args, t_sphere *sp, t_vec *ray, t_pxl *pxl)
{
	float	dist;
	t_qec	qec;
	t_vec	cam_sp;

	cam_sp = vect_substract(args->origin, sp->vcenter);
	qec.a = 1;
	qec.b = 2 * (vect_dot_product(cam_sp, *ray));
	qec.c = vect_dot_product(cam_sp, cam_sp) - powf(sp->d / 2, 2);
	dist = find_dists(sp, ray, qec);
	if (dist && dist < pxl->dist)
	{
		pxl->type = SPHERE;
		pxl->dist = dist;
		ft_memcpy(&pxl->rgb, &sp->color, sizeof(sp->color));
		pxl->vh_norma = sp->vh_norma;
		pxl->vh_point = sp->vh_point;
	}
}
