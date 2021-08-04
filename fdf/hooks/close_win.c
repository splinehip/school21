/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:55:37 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/04 12:01:52 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_win(t_fdf *vars)
{
	ft_printf("DESTROY EVENT: close win, break mlx_loop\n");
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_loop_end(vars->mlx);
	return (0);
}
