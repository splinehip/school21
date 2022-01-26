/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:28:51 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:28:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "args.h"

void	hooks_reg(t_args *args);
int		key_press(int keycode, t_args *args);
int		key_reales(int keycode, t_args *args);
int		mouse_btn(int btn, int x, int y, t_args *args);
int		mouse_move(int x, int y, t_args *args);
int		ptr_enter_win(t_args *args);
int		ptr_leave_win(t_args *args);
int		close_win(t_args *args);

#endif
