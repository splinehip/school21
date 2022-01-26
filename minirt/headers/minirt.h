/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:49:59 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/26 17:47:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# ifdef __APPLE__
#  define MACOS 1

int	mlx_destroy_display(void *mlx);
# else
#  define MACOS 0
# endif

# define PROG_NAME "miniRT Project"

int	main(int argc, char **argv);

#endif
