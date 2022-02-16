/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:20:02 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 16:39:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "libft.h"
#include "scene_handler.h"

void	init_vect(t_vec *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	normalise_vect(t_vec *vect)
{
	float	len;

	len = vect_len(*vect);
	if (!len)
	{
		vect->x = 0;
		vect->y = 0;
		vect->z = 0;
	}
	else
	{
		vect->x /= len;
		vect->y /= len;
		vect->z /= len;
	}
}

float	vect_dot_product(t_vec v1, t_vec v2)
{
	float	res;

	res = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return (res);
}

float	vector_scalar(t_vec v1, t_vec v2)
{
	float	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

t_vec	reflect_vect(t_vec ray, t_vec norm)
{
	t_vec	res;

	res = vect_mult(norm, 2);
	res = vect_mult(res, vector_scalar(norm, ray));
	res = vect_substract(res, ray);
	return (res);
}
