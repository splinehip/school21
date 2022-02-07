/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:04:59 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/07 13:10:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "args.h"
#include "msg_err.h"
#include "logger.h"
#include "input_handler.h"

inline void	set_fov(t_arg *args, char *str)
{
	args->camera.fov = ft_atoi(str);
	if (args->camera.fov < FOV_MIN || args->camera.fov > FOV_MAX)
	{
		print_err(MSG_INVALRANGE);
		logger("camera.fov: %i is out of range: %i - %i\n",
			args->camera.fov, FOV_MIN, FOV_MAX);
		exit(unsuccess);
	}
	logger("camera.fov: %i\n", args->camera.fov);
}
