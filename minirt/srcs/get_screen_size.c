/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:02:19 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 14:12:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "get_screen_size.h"

/*
It takes mlx_ptr, but it doesn't use it in mac os (because macOS is sheit).
This function can only get Main Screen, you should be careful when you use
multiple monitors...
*/
int	get_screen_size(void *mlx, int *x, int *y)
{
	if (MACOS)
		return (macos_get_screen_size(x, y));
	else
		return (mlx_get_screen_size(mlx, x, y));
}
