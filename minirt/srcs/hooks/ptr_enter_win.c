/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_enter_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:03:28 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:26:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "hooks.h"

int	ptr_enter_win(t_args *vars)
{
	(void)vars;
	printf("PTR ENTER WINDOW\n");
	return (0);
}
