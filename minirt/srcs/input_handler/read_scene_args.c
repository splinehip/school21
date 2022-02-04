/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:09:34 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/01 15:16:49 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "libft.h"

#include "bool.h"
#include "msg_err.h"
#include "logger.h"
#include "input_handler.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	update_args(t_arg *args, char *line)
{
	char	**strs;

	strs = ft_split(line, ' ');
	if (strs == NULL || strs[0] == NULL)
		logger("%s: >%s< %s", "update_args: Line spliting", line, MSG_RESNULL);
	else if (ft_strcmp(strs[0], AMBIENT) == 0)
		set_ambient(args, strs);
	else if (ft_strcmp(strs[0], LIGHT) == 0)
		set_light(args, strs);
	else if (ft_strcmp(strs[0], CAMERA) == 0)
		set_camera(args, strs);
	else if (ft_strcmp(strs[0], SPHERE) == 0)
		set_sphere(args, strs);
	else if (ft_strcmp(strs[0], PLANE) == 0)
		set_plane(args, strs);
	else if (ft_strcmp(strs[0], CYLINDER) == 0)
		set_cylinder(args, strs);
	else
	{
		print_err(MSG_UNDEFID);
		logger("%s: %s: %s", "Update args error", strs[0], MSG_UNDEFID);
	}
	free_strs(strs);
}

void	do_read(t_arg *args, int fd)
{
	int		res;
	char	*line;

	line = NULL;
	res = ft_gnl(fd, &line);
	while (res)
	{
		if (res < 0)
		{
			print_err(MSG_ERRREAD);
			logger("%s: %s", "File read error", MSG_ERRREAD);
			exit(unsuccess);
		}
		update_args(args, line);
		free(line);
		line = NULL;
		res = ft_gnl(fd, &line);
	}
	free(line);
}

void	read_scene_args(t_arg *args, char *file)
{
	int		fd;
	char	*pchar;

	pchar = ft_strrchr(file, '.');
	if (pchar == NULL || ft_strcmp(pchar, ".rt") != 0)
	{
		print_err(MSG_ERRFILEEXT);
		logger("%s: %s, %s", "Arguments error", file, MSG_ERRFILEEXT);
		exit(unsuccess);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_err(strerror(errno));
		logger("%s: %s: %s\n", "Arguments error", file, strerror(errno));
		exit(unsuccess);
	}
	do_read(args, fd);
	close(fd);
}
