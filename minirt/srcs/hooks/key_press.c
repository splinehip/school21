/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:14:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:25:25 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"

#include "bool.h"
#include "key_codes.h"
#include "hooks.h"

int	key_press(int keycode, t_args *vars)
{
	printf("KEY_PRESSED: %i\n", keycode);
	if (keycode == CTRL)
		vars->cntl = true;
	if (keycode == ESC)
		close_win(vars);
	return (0);
}
