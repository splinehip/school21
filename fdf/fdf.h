/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:48:30 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/04 15:50:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "key_cods.h"
# include "events_masks.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

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
	int		ctrl;
}	t_fdf;

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

#endif
