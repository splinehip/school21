/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:48:54 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/07 17:40:37 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "bool.h"
#include "enums.h"
#include "mesages.h"
#include "error_msgs.h"
#include "input_handler.h"
#include "actions_handler.h"
#include "minishell.h"

static inline void	do_input(
	t_action action, t_redirect *redirect, int *pipe_in)
{
	int	fd;

	if (redirect->target == NULL && pipe_in)
		dup2(action.pipe_in, 0);
	else if (redirect->target)
	{
		fd = get_redirect_fd(*redirect);
		if (fd > 0)
			dup2(fd, 0);
		close(fd);
	}
	*pipe_in = false;
}

static inline void	do_output(
	t_action action, t_redirect *redirect, int *pipe_out)
{
	int	fd;

	if (redirect->target == NULL && pipe_out)
		dup2(action.pipe_out, 1);
	else if (redirect->target)
	{
		fd = get_redirect_fd(*redirect);
		if (fd > 0)
			dup2(fd, 1);
		close(fd);
	}
	*pipe_out = false;
}

static inline void	do_read_input_redirect(void)
{
	int		fd;

	fd = open(READ_INPUT_FILE, O_RDONLY);
	if (fd > 0)
		dup2(fd, 0);
	else
		perror(MSG_PROG_NAME);
	close(fd);
}

inline void	do_redirects(t_action action, char **env)
{
	int	i;
	int	pipe_in;
	int	pipe_out;
	int	read_input_res;

	i = 0;
	pipe_in = true;
	pipe_out = true;
	read_input_res = false;
	while (i < action.redirects.len)
	{
		if (action.redirects.item[i].type == input)
			do_input(action, &action.redirects.item[i], &pipe_in);
		if (action.redirects.item[i].type == read_input)
			do_read_input(action.redirects.item[i].target, &read_input_res,
				&pipe_in, env);
		if (action.redirects.item[i].type == output
			|| action.redirects.item[i].type == output_append)
			do_output(action, &action.redirects.item[i], &pipe_out);
		i++;
	}
	if (read_input_res)
		do_read_input_redirect();
}
