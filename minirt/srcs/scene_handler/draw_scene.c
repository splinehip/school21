/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:25:57 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 17:57:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "mlx.h"

#include "bool.h"
#include "libft.h"
#include "scene_handler.h"

typedef struct s_proj
{
	float	w;
	float	h;
	float	x_pix;
	float	y_pix;
}	t_proj;

typedef struct s_draw
{
	int		mlx_x;
	int		mlx_y;
	int		color;
	float	x_angle;
	float	y_angle;
	float	y_ray;
	float	x_ray;
	t_vec	ray;
	t_proj	proj;
}	t_draw;

static inline void	scene_projection(t_arg *args, t_draw *draw)
{
	float	ratio;

	ratio = (float)args->window_width / (float)args->window_height;
	draw->proj.w = tan(args->camera.fov / 2 * (M_PI / 180));
	draw->proj.w *= 2;
	draw->proj.h = draw->proj.w / ratio;
	draw->proj.x_pix = draw->proj.w / args->window_width;
	draw->proj.y_pix = draw->proj.h / args->window_height;
}

static int	offscreen(t_arg *args, int x, int y)
{
	if (x < 0 || x >= args->window_width)
		return (1);
	if (y < 0 || y >= args->window_height)
		return (true);
	return (false);
}

static inline void	put_pixel(t_arg *args, int x, int y, int color)
{
	char	*dst;

	if (offscreen(args, x, y))
		return ;
	dst = args->img_addr + (y * args->length + x * (args->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_scene(t_arg *args)
{
	t_draw	draw;

	draw.mlx_y = 0;
	scene_projection(args, &draw);
	draw.y_angle = (args->window_height / 2.0);
	while (draw.y_angle >= (args->window_height / 2.0) * -1.0)
	{
		draw.mlx_x = 0;
		draw.y_ray = draw.y_angle * draw.proj.y_pix;
		draw.x_angle = (args->window_width / 2) * -1.0;
		while (draw.x_angle <= (args->window_width / 2.0))
		{
			draw.x_ray = draw.x_angle * draw.proj.x_pix;
			init_vect(&draw.ray, draw.x_ray, draw.y_ray, -1.0);
			normalise_vect(&draw.ray);
			culc_color(args, &draw.ray, &draw.color);
			put_pixel(args, draw.mlx_x, draw.mlx_y, draw.color);
			draw.mlx_x++;
			draw.x_angle++;
		}
		draw.mlx_y++;
		draw.y_angle--;
	}
}
