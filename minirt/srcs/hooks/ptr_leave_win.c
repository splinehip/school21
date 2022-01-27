/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_leave_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:05:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:26:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "hooks.h"

int	ptr_leave_win(t_arg *vars)
{
	(void)vars;
	printf("PTR LEAVE WINDOW\n");
	return (0);
}
