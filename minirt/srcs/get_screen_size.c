/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:02:19 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 13:29:37 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_screen_size.h"

#ifdef __APPLE__
int	macos_get_screen_size(int *size_x, int *size_y)
{
	NSRect	e;

	e = [[NSScreen mainScreen] frame];
	*size_x = (int)e.size.width;
	*sizey = (int)e.size.height;
	return (0);
}

#endif

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
