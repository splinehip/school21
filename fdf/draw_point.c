/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:35:08 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/04 15:36:25 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_fdf *vars, int x, int y, int color)
{
	char	*point;

	point = vars->img_addr + (
			y * vars->length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)point = color;
}
