/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:27:50 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 17:19:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "libft.h"
#include "bool.h"
#include "scene_handler.h"

static inline t_vec	res_hit_dir(void *obj, char *obj_type)
{
	int		*inside;
	t_vec	*vh_norm;

	inside = NULL;
	if (ft_strcmp(obj_type, SPHERE) == 0)
	{
		inside = &((t_sphere *)obj)->inside;
		vh_norm = &((t_sphere *)obj)->vh_norma;
	}
	else if (ft_strcmp(obj_type, PLANE) == 0)
	{
		inside = &((t_plane *)obj)->inside;
		vh_norm = &((t_plane *)obj)->vh_norma;
	}
	else if (ft_strcmp(obj_type, CYLINDER) == 0)
	{
		inside = &((t_cylinder *)obj)->inside;
		vh_norm = &((t_cylinder *)obj)->vh_norma;
	}
	else
		return ((t_vec){0, 0, 0});
	if (inside)
		*vh_norm = vect_mult(*vh_norm, -1);
	normalise_vect(vh_norm);
	return (*vh_norm);
}

t_vec	get_hit_direction(void *obj, char *obj_type, t_vec ray)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	if (ft_strcmp(obj_type, SPHERE) == 0)
	{
		sp = (t_sphere *)obj;
		sp->vh_norma = vect_substract(sp->vh_point, sp->vcenter);
	}
	else if (ft_strcmp(obj_type, PLANE) == 0)
	{
		pl = (t_plane *)obj;
		pl->inside = false;
		pl->vh_norma = pl->vnorma;
		if (vect_dot_product(ray, pl->vnorma) > 0.0)
			pl->vh_norma = vect_mult(pl->vh_norma, -1);
	}
	else if (ft_strcmp(obj_type, CYLINDER) == 0)
	{
		cy = (t_cylinder *)obj;
		cy->inside = false;
	}
	return (res_hit_dir(obj, obj_type));
}

inline void	check_pxl_intersects(t_arg *args, t_vec *ray, t_pxl *pxl)
{
	int	i;

	i = 0;
	while (true)
	{
		if (i < args->objs.sp_len)
			sphere_intersects(args, &args->objs.sp[i], ray, pxl);
		if (i < args->objs.pl_len)
			plane_intersects(args, &args->objs.pl[i], ray, pxl);
		if (i < args->objs.cy_len)
			cylinder_intersects(args, &args->objs.cy[i], ray, pxl);
		if (i >= args->objs.sp_len && i >= args->objs.pl_len
			&& i >= args->objs.cy_len)
			break ;
		i++;
	}
}

void	culc_color(t_arg *args, t_vec *ray, int *color)
{
	t_pxl	pxl;

	pxl.dist = MAX_DIST;
	ft_memset(&pxl.rgb, 0, sizeof(pxl.rgb));
	pxl.color = COLOR_BLACK;
	ft_memset(&pxl.vh_norma, 0, sizeof(pxl.vh_norma));
	ft_memset(&pxl.vh_point, 0, sizeof(pxl.vh_point));
	args->origin = args->camera.vpoint;
	check_pxl_intersects(args, ray, &pxl);
	set_pxl_color(args, ray, &pxl);
	*color = pxl.color;
}
