/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:23:04 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 16:33:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "bool.h"
#include "scene_handler.h"

static inline void	update_dist(t_cylinder *cy, t_vec *ray, t_org *org)
{
	org->dist = org->caps.root_1;
	org->m = org->caps.m_1;
	cy->vh_point = vect_mult(*ray, org->dist);
	cy->vh_norma = cy->vnorma;
	if (vect_dot_product(*ray, cy->vnorma) > 0.0)
		cy->vh_norma = vect_mult(cy->vh_norma, -1);
	normalise_vect(&cy->vh_norma);
}

static inline int	do_return(t_cylinder *cy, t_vec *ray, t_org *org)
{
	if (!get_caps(cy, ray, org) && !in_range(org->qec.m_1, cy->h)
		&& !in_range(org->qec.m_2, cy->h))
	{
		org->dist = 0;
		return (true);
	}
	if (in_range(org->qec.m_1, cy->h)
		&& (org->qec.root_1 < org->caps.root_1 || org->caps.root_1 < MIN_DIST))
	{
		org->dist = org->qec.root_1;
		org->m = org->qec.m_1;
	}
	else if (in_range(org->qec.m_2, cy->h)
		&& (org->qec.root_2 < org->caps.root_1 || org->caps.root_1 < MIN_DIST))
	{
		org->dist = org->qec.root_2;
		org->m = org->qec.m_2;
	}
	else
	{
		update_dist(cy, ray, org);
		return (true);
	}
	return (false);
}

static inline float	get_dist(t_cylinder *cy, t_vec *ray, t_org *org)
{
	ft_memset(&org->caps, 0, sizeof(t_qec));
	if (in_range(org->qec.m_1, cy->h) && in_range(org->qec.m_2, cy->h))
	{
		org->dist = org->qec.root_1;
		org->m = org->qec.m_1;
		if (org->qec.root_1 > org->qec.root_2)
			org->dist = org->qec.root_2;
		if (org->qec.root_1 > org->qec.root_2)
			org->m = org->qec.m_2;
	}
	else if (do_return(cy, ray, org))
		return (org->dist);
	cy->vh_point = vect_mult(*ray, org->dist);
	cy->vh_norma = vect_substract(cy->vh_point, cy->vpoint);
	org->vres = vect_mult(cy->vnorma, org->m);
	cy->vh_norma = vect_substract(cy->vh_norma, org->vres);
	normalise_vect(&cy->vh_norma);
	return (org->dist);
}

static inline float	find_dists_cy(t_cylinder *cy, t_vec *ray, t_org *org)
{
	org->qec.discr = org->qec.b * org->qec.b - (4 * org->qec.a * org->qec.c);
	if (org->qec.discr < 0.0)
		return (0);
	org->qec.discr = sqrt(org->qec.discr);
	org->qec.root_1 = (-org->qec.b - org->qec.discr) / (2 * org->qec.a);
	org->qec.root_2 = (-org->qec.b + org->qec.discr) / (2 * org->qec.a);
	org->qec.m_1 = vect_dot_product(*ray, cy->vnorma) * org->qec.root_1
		+ vect_dot_product(org->cam_cy, cy->vnorma);
	org->qec.m_2 = vect_dot_product(*ray, cy->vnorma) * org->qec.root_2
		+ vect_dot_product(org->cam_cy, cy->vnorma);
	if (org->qec.root_1 <= MIN_DIST)
		org->qec.m_1 = cy->h + 1.0;
	if (org->qec.root_2 <= MIN_DIST)
		org->qec.m_2 = cy->h + 1.0;
	return (get_dist(cy, ray, org));
}

void	cylinder_intersects(t_arg *args, t_cylinder *cy, t_vec *ray, t_pxl *pxl)
{
	float	dist;
	float	dot_r_nv;
	float	dot_cc_nv;
	t_org	org;

	org.cam_cy = vect_substract(args->origin, cy->vpoint);
	normalise_vect(&cy->vnorma);
	dot_r_nv = vect_dot_product(*ray, cy->vnorma);
	dot_cc_nv = vect_dot_product(org.cam_cy, cy->vnorma);
	org.qec.a = vect_dot_product(*ray, *ray) - dot_r_nv * dot_r_nv;
	org.qec.b = 2 * (vect_dot_product(*ray, org.cam_cy) - dot_r_nv * dot_cc_nv);
	org.qec.c = vect_dot_product(org.cam_cy, org.cam_cy)
		- dot_cc_nv * dot_cc_nv - pow(cy->d / 2, 2);
	dist = find_dists_cy(cy, ray, &org);
	if (dist && dist < pxl->dist)
	{
		pxl->type = CYLINDER;
		pxl->dist = dist;
		ft_memcpy(&pxl->rgb, &cy->color, sizeof(cy->color));
		pxl->vh_norma = cy->vh_norma;
		pxl->vh_point = cy->vh_point;
	}
}
