/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersects_caps.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:02:36 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 16:15:31 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "bool.h"
#include "scene_handler.h"

inline int	in_range(float num, float range)
{
	if (num > range || num < -range)
		return (false);
	return (true);
}

static inline void	check_roots(t_cylinder *cy, t_vec *ray, t_org *org)
{
	if (org->caps.root_1 >= MIN_DIST)
	{
		org->hit[0] = vect_mult(*ray, org->caps.root_1);
		org->pl_1 = vect_add(cy->vpoint, vect_mult(cy->vnorma, org->caps.m_1));
	}
	if (org->caps.root_2 >= MIN_DIST)
	{
		org->hit[1] = vect_mult(*ray, org->caps.root_2);
		org->pl_2 = vect_add(cy->vpoint, vect_mult(cy->vnorma, org->caps.m_2));
	}
	org->res[0] = (org->caps.root_1 >= MIN_DIST
			&& fabs(point_dist(org->hit[0], org->pl_1)) <= cy->d / 2);
	org->res[1] = (org->caps.root_2 >= MIN_DIST
			&& fabs(point_dist(org->hit[1], org->pl_2)) <= cy->d / 2);
}

inline int	get_caps(t_cylinder *cy, t_vec *ray, t_org *org)
{
	normalise_vect(&cy->vnorma);
	org->dot_r_nv = vect_dot_product(*ray, cy->vnorma);
	if (org->dot_r_nv == 0 || fabs(org->dot_r_nv) < MIN_DIST)
		return (0);
	org->caps.m_1 = cy->h;
	org->caps.m_2 = -cy->h;
	org->pl_1 = vect_substract((t_vec){0, 0, 0},
			vect_add(cy->vpoint, vect_mult(cy->vnorma, org->caps.m_1)));
	org->pl_2 = vect_substract((t_vec){0, 0, 0},
			vect_add(cy->vpoint, vect_mult(cy->vnorma, org->caps.m_2)));
	org->caps.root_1 = -vect_dot_product(org->pl_1, cy->vnorma) / org->dot_r_nv;
	org->caps.root_2 = -vect_dot_product(org->pl_2, cy->vnorma) / org->dot_r_nv;
	if (org->caps.root_1 < MIN_DIST && org->caps.root_2 < MIN_DIST)
		return (0);
	check_roots(cy, ray, org);
	if (!org->res[0] && !org->res[1])
		return (false);
	if ((org->res[0] && org->res[1] && org->caps.root_2 < org->caps.root_1)
		|| !org->res[0])
	{
		org->caps.root_1 = org->caps.root_2;
		org->caps.m_1 = org->caps.m_2;
	}
	return (true);
}
