/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:48:54 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/04 16:09:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "bool.h"
#include "enums.h"
#include "actions_handler.h"

static inline void	do_input(t_action action, t_redirect *redirect)
{
	int	fd;

	if (redirect->target == NULL)
	{
		dup2(action.pipe_in, 0);
		//close(action.pipe_out);
	}
	else
	{
		fd = open(redirect->target, O_RDONLY);
		if (fd < 0)
		{
			perror("minishell");
			return ;
		}
		dup2(fd, 0);
		close(fd);
	}
}

static inline void	do_output(t_action action, t_redirect *redirect)
{
	int	fd;

	if (redirect->target == NULL)
	{
		dup2(action.pipe_out, 1);
		//close(action.pipe_out);
	}
	else
	{
		fd = open(redirect->target, O_WRONLY | O_TRUNC | O_CREAT, 0664);
		if (fd < 0)
		{
			perror("minishell");
			return ;
		}
		dup2(fd, 1);
		close(fd);
	}
}

inline void	do_redirects(t_action action, char **env)
{
	int	i;

	(void)env;
	i = 0;
	while (i < action.redirects.len)
	{
		if (action.redirects.item[i].type == input)
			do_input(action, &action.redirects.item[i]);
		if (action.redirects.item[i].type == output)
			do_output(action, &action.redirects.item[i]);
		i++;
	}
}
