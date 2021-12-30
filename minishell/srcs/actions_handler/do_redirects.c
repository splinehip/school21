/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:48:54 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/30 13:46:54 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "bool.h"
#include "enums.h"
#include "actions_handler.h"

inline void	do_redirects(t_redirect *redirects, int *pipes, char **env)
{
	int	i;
	int	fd;

	(void)redirects;
	(void)env;
	(void)pipes;
	if (redirects == NULL)
		return ;
	i = 0;
	while (redirects[i].end == false)
	{
		if (redirects[i].type == input)
		{
			if (redirects[i].target == NULL)
				dup2(pipes[0], 0);
			else
			{
				fd = open(redirects[i].target, O_RDONLY);
				dup2(fd, 0);
				close(fd);
			}
		}
		else if (redirects[i].type == output)
		{
			if (redirects[i].target == NULL)
				dup2(pipes[1], 1);
			else
			{
				fd = open(redirects[i].target,
						O_WRONLY | O_TRUNC | O_CREAT, 0664);
				dup2(fd, 1);
				close(fd);
			}
		}
		i++;
	}
}
