/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:49:59 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/16 17:40:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "args.h"
# include "os_dep.h"
# define PROG_NAME "miniRT Project"

int		main(int argc, char **argv);
void	free_args(t_arg *args);

#endif
