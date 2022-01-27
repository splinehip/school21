/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:55:37 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 18:14:11 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "mlx.h"

#include "bool.h"
#include "minirt.h"
#include "hooks.h"

int	close_win(t_arg *args)
{
	printf("DESTROY EVENT: close win, break mlx_loop\n");
	if (MACOS == false)
		mlx_loop_end(args->mlx);
	else
	{
		free_args(args);
		exit(success);
	}
	return (0);
}
