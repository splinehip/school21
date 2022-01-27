/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_reales.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:46:17 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/27 10:52:54 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "bool.h"
#include "key_codes.h"
#include "hooks.h"

int	key_reales(int keycode, t_arg *vars)
{
	printf("KEY REALESED: %i\n", keycode);
	if (keycode == CTRL)
		vars->cntl = false;
	return (0);
}
