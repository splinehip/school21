/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_size.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:09:03 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 13:49:17 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_SCREEN_SIZE_H
# define GET_SCREEN_SIZE_H
# ifdef __APPLE__
#  define MACOS 1
#  int	macos_get_screen_size(int *size_x, int *size_y);
# else
#  define MACOS 0
#  include "mlx.h"
# endif

int	get_screen_size(void *mlx, int *x, int *y);
int	macos_get_screen_size(int *size_x, int *size_y);

#endif
