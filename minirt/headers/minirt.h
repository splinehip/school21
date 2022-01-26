/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:49:59 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 19:13:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
#
#include "args.h"
#
# define PROG_NAME "miniRT Project"
# ifdef __APPLE__
#  define MACOS 1

/*
dummy funcs for macos
*/
int	mlx_destroy_display(void *mlx);
int	mlx_loop_end(void *mlx);
# else
#  define MACOS 0
# endif

int		main(int argc, char **argv);
void	free_args(t_args *args);

#endif
