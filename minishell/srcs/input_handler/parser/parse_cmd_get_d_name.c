/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_get_d_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:53:00 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/13 10:41:27 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

#include "builtins.h"

char	*get_d_name(void)
{
	static DIR		*dir;
	struct dirent	*dir_ent;
	char			*pwd;

	dir_ent = NULL;
	if (dir == NULL)
	{
		pwd = getcwd(NULL, 0);
		if (pwd)
			dir = opendir(pwd);
		free(pwd);
	}
	if (dir)
		dir_ent = readdir(dir);
	if (dir_ent)
		return (dir_ent->d_name);
	else
	{
		if (dir)
			closedir(dir);
		dir = NULL;
		return (NULL);
	}
}
