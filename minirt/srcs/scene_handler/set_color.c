/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:55:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 16:39:30 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "bool.h"
#include "scene_handler.h"

static inline int	intersection_exists(t_arg *args, t_pxl *intersect)
{
	t_vec	ray;

	intersect->dist = MAX_DIST;
	ray = intersect->vh_norma;
	args->origin = intersect->vh_point;
	check_pxl_intersects(args, &ray, intersect);
	if (intersect->dist == MAX_DIST)
		return (false);
	return (true);
}

static inline int	in_shadow(t_arg *args, t_pxl *pxl)
{
	t_pxl	intersect;
	float	dist_to_light;
	float	dist_to_obj;

	intersect.vh_point = vect_add(pxl->vh_point,
			vect_mult(pxl->vh_norma, 0.00001));
	intersect.vh_norma = vect_substract(args->light.vpoint, intersect.vh_point);
	normalise_vect(&intersect.vh_norma);
	if (intersection_exists(args, &intersect))
	{
		dist_to_light = vect_dist(pxl->vh_point, args->light.vpoint);
		dist_to_obj = vect_dist(pxl->vh_point, intersect.vh_point);
		if (dist_to_obj < dist_to_light)
			return (true);
	}
	return (false);
}

static inline void	add_light(
	t_arg *args, t_pxl *pxl, t_rgb ambtrgb, t_rgb lightrgb)
{
	float	light;
	float	n_dot_l;
	t_rgb	ambient;
	t_rgb	diffuse;
	t_vec	l_len;

	light = args->ambient.alr;
	ambient = calc_rgb_light(ambtrgb, light);
	l_len = vect_substract(args->light.vpoint, pxl->vh_point);
	n_dot_l = vect_dot_product(pxl->vh_norma, args->light.vpoint);
	if (n_dot_l <= 0.0 && ft_strcmp(pxl->type, PLANE) == 0)
	{
		pxl->vh_norma = vect_mult(pxl->vh_norma, -1.0);
		n_dot_l *= -1.0;
	}
	if (n_dot_l > 0.0)
	{
		light = args->light.lbr * n_dot_l
			/ (vect_len(pxl->vh_norma) * vect_len(l_len));
		diffuse = calc_rgb_light(lightrgb, light);
		ambient = add_rgb_light(ambient, diffuse);
	}
	pxl->trgb = multiply_rgbs(pxl->trgb, ambient);
	pxl->color = rgb_hex(0, pxl->trgb);
}

static inline void	add_specular(
	t_arg *args, t_vec ray, t_pxl *pxl, t_rgb lightrgb)
{
	t_vec	reflect;
	t_rgb	spec;
	double	strength;
	float	r_dot_v;

	reflect = reflect_vect(vect_mult(args->light.vpoint, -1.0), pxl->vh_norma);
	r_dot_v = vect_dot_product(reflect, ray);
	if (r_dot_v > 0.0)
	{
		strength = args->light.lbr
			* pow(r_dot_v / vect_len(reflect) * vect_len(ray), 32);
		spec = calc_rgb_light(lightrgb, 0.6 * strength);
		pxl->color = rgb_hex(0, add_rgb_light(pxl->trgb, spec));
	}
}

void	set_pxl_color(t_arg *args, t_vec *ray, t_pxl *pxl)
{
	t_rgb	ambtrgb;
	t_rgb	lightrgb;

	if (pxl->dist == MAX_DIST)
		return ;
	pxl->trgb.r = pxl->rgb[r];
	pxl->trgb.g = pxl->rgb[g];
	pxl->trgb.b = pxl->rgb[b];
	ambtrgb.r = args->ambient.color[r];
	ambtrgb.g = args->ambient.color[g];
	ambtrgb.b = args->ambient.color[b];
	lightrgb.r = args->light.color[r];
	lightrgb.g = args->light.color[g];
	lightrgb.b = args->light.color[b];
	if (in_shadow(args, pxl))
	{
		pxl->trgb = multiply_rgbs(
				pxl->trgb, calc_rgb_light(ambtrgb, args->ambient.alr));
		pxl->color = rgb_hex(0, pxl->trgb);
	}
	else
	{
		add_light(args, pxl, ambtrgb, lightrgb);
		add_specular(args, *ray, pxl, lightrgb);
	}
}
