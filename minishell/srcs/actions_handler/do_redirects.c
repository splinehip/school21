/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:48:54 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/05 17:04:22 by cflorind         ###   ########.fr       */
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
#include "error_msgs.h"
#include "actions_handler.h"

inline int	get_redirects_fd(t_redirect redirect)
{
	int	fd;

	fd = -1;
	if (redirect.type == input)
		fd = open(redirect.target, O_RDONLY);
	else if (redirect.type == output)
		fd = open(redirect.target, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	else if (redirect.type == output_append)
		fd = open(redirect.target, O_WRONLY | O_APPEND | O_CREAT, 0664);
	else
	{
		printf(MSG_ERR_INRDTYPE);
		return (fd);
	}
	if (fd < 0)
		perror("minishell");
	return (fd);
}

static inline void	do_input(t_action action, t_redirect *redirect)
{
	int	fd;

	if (redirect->target == NULL)
		dup2(action.pipe_in, 0);
	else if (redirect->type == input)
	{
		fd = get_redirects_fd(*redirect);
		if (fd > 0)
		{
			dup2(fd, 0);
			close(fd);
		}
	}
}

static inline void	do_output(t_action action, t_redirect *redirect)
{
	int	fd;

	if (redirect->target == NULL)
		dup2(action.pipe_out, 1);
	else
	{
		fd = get_redirects_fd(*redirect);
		if (fd > 0)
		{
			dup2(fd, 1);
			close(fd);
		}
	}
}

inline void	do_redirects(t_action action, char **env)
{
	int	i;

	(void)env;
	i = 0;
	while (i < action.redirects.len)
	{
		if (action.redirects.item[i].type == input
			|| action.redirects.item[i].type == read_input)
			do_input(action, &action.redirects.item[i]);
		if (action.redirects.item[i].type == output
			|| action.redirects.item[i].type == output_append)
			do_output(action, &action.redirects.item[i]);
		i++;
	}
}
