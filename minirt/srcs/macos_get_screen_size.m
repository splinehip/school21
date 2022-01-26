/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macos_get_screen_size.m                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:45:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 14:16:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <AppKit/NSOpenGLView.h>

int	mlx_get_screen_size(void *mlx, int *x, int *y)
{
	return (0);
}

int	macos_get_screen_size(int *size_x, int *size_y)
{
	NSRect	e;

	e = [[NSScreen mainScreen] frame];
	*size_x = (int)e.size.width;
	*sizey = (int)e.size.height;
	return (0);
}
