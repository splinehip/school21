/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_reales.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:46:17 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:01:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "key_codes.h"
#include "hooks.h"

int	key_reales(int keycode, t_args *vars)
{
	if (keycode == CTRL)
		vars->cntl = false;
	return (0);
}
