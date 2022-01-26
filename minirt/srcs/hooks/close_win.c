/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:55:37 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:24:35 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"

#include "hooks.h"

int	close_win(t_args *vars)
{
	printf("DESTROY EVENT: close win, break mlx_loop\n");
	mlx_loop_end(vars->mlx);
	return (0);
}
