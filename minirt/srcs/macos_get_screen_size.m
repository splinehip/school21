/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macos_get_screen_size.m                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:45:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 13:47:57 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <AppKit/NSOpenGLView.h>

int	macos_get_screen_size(int *size_x, int *size_y)
{
	NSRect	e;

	e = [[NSScreen mainScreen] frame];
	*size_x = (int)e.size.width;
	*sizey = (int)e.size.height;
	return (0);
}
