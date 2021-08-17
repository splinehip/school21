/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:48:30 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/17 17:50:43 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "key_cods.h"
# include "events_masks.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# define X 0
# define Y 1
# define Z 2

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		length;
	int		endian;
	int		x_size;
	int		y_size;
	int		**map;
	int		map_size_x;
	int		map_size_y;
	int		map_max_z;
	int		map_min_z;
	int		ctrl;
}	t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	hooks_reg(t_fdf *vars);
int		key_press(int keycode, t_fdf *vars);
int		key_reales(int keycode, t_fdf *vars);
int		mouse_btn(int btn, int x, int y, t_fdf *vars);
int		mouse_move(int x, int y, t_fdf *vars);
int		ptr_enter_win(t_fdf *vars);
int		ptr_leave_win(t_fdf *vars);
int		close_win(t_fdf *vars);
int		trgb(int t, int r, int g, int b);
void	draw_point(t_fdf *vars, int x, int y, int color);
void	draw_line(t_point start, t_point end, t_fdf *vars);
void	argv_handler(char *file, t_fdf *vars);

#endif
