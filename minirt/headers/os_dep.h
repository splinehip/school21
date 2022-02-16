/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_dep.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:40:13 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 17:40:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_DEP_H
# define OS_DEP_H
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
#endif
