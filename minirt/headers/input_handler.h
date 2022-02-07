/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:12:45 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/07 13:06:47 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HADNLER_H
# include "args.h"

void	read_scene_args(t_arg *args, char *file);
void	set_ambient(t_arg *args, char **strs);
void	set_light(t_arg *args, char **strs);
void	set_camera(t_arg *args, char **strs);
void	set_fov(t_arg *args, char *str);
void	set_sphere(t_arg *args, char **strs);
void	set_plane(t_arg *args, char **strs);
void	set_cylinder(t_arg *args, char **strs);

#endif
