/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:48:30 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/25 11:56:18 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <string.h>
# include "key_codes.h"
# include "events_masks.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

enum	e_axis
{
	X = 0,
	Y = 1,
	Z = 2,
};

enum e_base_colors
{
	BLUE	= 0x0000ff,
	GREEN	= 0x00ff00,
	YELOW	= 0xffff00,
	BROWN	= 0x52361b,
};

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		length;
	int		endian;
	int		screen_size_x;
	int		screen_size_y;
	int		***map;
	int		map_size_x;
	int		map_size_y;
	int		map_max_z;
	int		map_min_z;
	int		map_scale;
	int		map_z_scale;
	int		display_line;
	int		ctrl;
	int		iso;
	double	alfa;
}	t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

void	hooks_reg(t_fdf *vars);
int		key_press(int keycode, t_fdf *vars);
int		key_reales(int keycode, t_fdf *vars);
int		mouse_btn(int btn, int x, int y, t_fdf *vars);
int		mouse_move(int x, int y, t_fdf *vars);
int		ptr_enter_win(t_fdf *vars);
int		ptr_leave_win(t_fdf *vars);
int		close_win(t_fdf *vars);
int		trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		color(int map_min_z, int map_max_z, int z);
int		gradient(int delta, int step, t_point start, t_point end);
void	draw_point(t_fdf *vars, int x, int y, int color);
void	draw_line(t_fdf *vars, t_point start, t_point end);
int		argv_handler(char *file, t_fdf *vars);
void	display_map(t_fdf *vars);
void	draw_map(t_fdf *vars, t_point offset);
void	rotate_x(t_fdf *vars, int ix, int iy, double alfa);
void	rotate_y(t_fdf *vars, int ix, int iy, double alfa);
void	rotate_z(t_fdf *vars, int ix, int iy, double alfa);
void	iso(t_fdf *vars, int ix, int iy);

#endif
