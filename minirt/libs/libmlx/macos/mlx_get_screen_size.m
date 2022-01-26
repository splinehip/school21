/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_screen_size.m                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:45:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 15:42:20 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <AppKit/NSOpenGLView.h>

#include "mlx.h"

/*
It takes mlx_ptr, but it doesn't use it in mac os (because macOS is sheit).
This function can only get Main Screen, you should be careful when you use
multiple monitors...
*/
int	mlx_get_screen_size(void *mlx, int *size_x, int *size_y)
{
	NSRect	e;

	(void)mlx;
	e = [[NSScreen mainScreen] frame];
	*size_x = (int)e.size.width;
	*size_y = (int)e.size.height;
	return (0);
}
