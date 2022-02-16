/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:58:22 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/15 14:58:47 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "scene_handler.h"

float	point_dist(t_vec v1, t_vec v2)
{
	float	res;

	res = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
	return (res);
}

float	vect_dist(t_vec v1, t_vec v2)
{
	float	res;

	res = (v1.x - v2.x) * (v1.x - v2.x)
		+ (v1.y - v2.y) * (v1.y - v2.y)
		+ (v1.z - v2.z) * (v1.z - v2.z);
	return (res);
}
