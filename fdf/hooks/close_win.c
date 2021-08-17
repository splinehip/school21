/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:55:37 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/17 16:16:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_win(t_fdf *vars)
{
	ft_printf("DESTROY EVENT: close win, break mlx_loop\n");
	mlx_loop_end(vars->mlx);
	return (0);
}
