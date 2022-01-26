/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:49:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:23:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "events_masks.h"
#include "hooks.h"

void	hooks_reg(t_args *vars)
{
	mlx_mouse_hook(vars->win, mouse_btn, vars);
	mlx_hook(vars->win, KEYPRESS, KEYPRESSMASK, key_press, vars);
	mlx_hook(vars->win, KEYRELEASE, KEYRELEASEMASK, key_reales, vars);
	mlx_hook(vars->win, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_move, vars);
	mlx_hook(vars->win, ENTERNOTIFY, ENTERWINDOWMASK, ptr_enter_win, vars);
	mlx_hook(vars->win, LEAVENOTIFY, LEAVEWINDOWMASK, ptr_leave_win, vars);
	mlx_hook(vars->win, DESTROYNOTIFY, BUTTONPRESSMASK, close_win, vars);
}
