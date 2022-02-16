/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:30:29 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/15 14:51:51 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "libft.h"
#include "scene_handler.h"

t_vec	vect_substract(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vec	vect_add(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec	vect_mult(t_vec vect, float n)
{
	t_vec	res;

	res.x = vect.x * n;
	res.y = vect.y * n;
	res.z = vect.z * n;
	return (res);
}

t_vec	vect_div(t_vec vect, float n)
{
	t_vec	res;

	res.x = vect.x / n;
	res.y = vect.y / n;
	res.z = vect.z / n;
	return (res);
}

float	vect_len(t_vec vect)
{
	float	res;

	res = sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2));
	return (res);
}
