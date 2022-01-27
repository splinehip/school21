/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_btn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:11:50 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:27:47 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "hooks.h"

int	mouse_btn(int btn, int x, int y, t_arg *args)
{
	(void)args;
	printf("btn: %i, x: %i, y: %i\n", btn, x, y);
	return (0);
}
