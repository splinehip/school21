/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:02:13 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 15:02:25 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_handler.h"

inline int	rgb_hex(int t, t_rgb rgb)
{
	return (t << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

inline t_rgb	calc_rgb_light(t_rgb trgb, double ratio)
{
	t_rgb	new;

	new.r = (int)((double)trgb.r * ratio);
	new.g = (int)((double)trgb.g * ratio);
	new.b = (int)((double)trgb.b * ratio);
	if (new.r > 255)
		new.r = 255;
	if (new.g > 255)
		new.g = 255;
	if (new.b > 255)
		new.b = 255;
	return (new);
}

inline t_rgb	multiply_rgbs(t_rgb a, t_rgb b)
{
	t_rgb	new;

	new.r = a.r * b.r / 255;
	new.g = a.g * b.g / 255;
	new.b = a.b * b.b / 255;
	return (new);
}

inline t_rgb	add_rgb_light(t_rgb a, t_rgb b)
{
	t_rgb	color;

	color.r = a.r + b.r;
	color.g = a.g + b.g;
	color.b = a.b + b.b;
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return (color);
}
