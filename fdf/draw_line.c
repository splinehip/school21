/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:39:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/18 11:15:42 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

struct s_draw_line
{
	int	x;
	int	y;
	int	d;
	int	dx;
	int	dy;
	int	len;
	int	len_x;
	int	len_y;
};

static inline void	init_args(struct s_draw_line *args,
	t_point start, t_point end)
{
	args->x = start.x;
	args->y = start.y;
	args->dx = 1;
	args->dy = 1;
	args->len_x = end.x - start.x;
	args->len_y = end.y - start.y;
	if (args->len_x < 0)
	{
		args->dx = -1;
		args->len_x *= -1;
	}
	if (args->len_y < 0)
	{
		args->dy = -1;
		args->len_y *= -1;
	}
	if (args->len_x > args->len_y)
		args->len = args->len_x;
	else
		args->len = args->len_y;
}

static inline void	draw_at_x(struct s_draw_line args, t_fdf *vars)
{
	args.d = -args.len_x;
	args.len++;
	while (args.len--)
	{
		draw_point(vars, args.x, args.y, trgb(0, 125, 125, 125));
		args.x += args.dx;
		args.d += 2 * args.len_y;
		if (args.d > 0)
		{
			args.y += args.dy;
			args.d -= 2 * args.len_x;
		}
	}
}

static inline void	draw_at_y(struct s_draw_line args, t_fdf *vars)
{
	args.d = -args.len_y;
	args.len++;
	while (args.len--)
	{
		draw_point(vars, args.x, args.y, trgb(0, 125, 125, 125));
		args.y += args.dy;
		args.d += 2 * args.len_x;
		if (args.d > 0)
		{
			args.x += args.dx;
			args.d -= 2 * args.len_y;
		}
	}
}

void	draw_line(t_fdf *vars, t_point start, t_point end, int color)
{
	struct s_draw_line	args;

	init_args(&args, start, end);
	if (args.len == 0)
		draw_point(vars, start.x, start.y, color);
	if (args.len_x >= args.len_y)
		draw_at_x(args, vars);
	else
		draw_at_y(args, vars);
}
