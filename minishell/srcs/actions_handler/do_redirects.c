/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:48:54 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/08 17:26:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"
#include "bool.h"
#include "enums.h"
#include "mesages.h"
#include "error_msgs.h"
#include "input_handler.h"
#include "actions_handler.h"
#include "minishell.h"

static inline void	do_input(t_action action, t_redirect *redirect)
{
	int	fd;

	if (redirect->target == NULL)
		dup2(action.pipe_in, STDIN_FILENO);
	else if (redirect->target)
	{
		fd = get_redirect_fd(*redirect);
		if (fd > 0)
		{
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
	}
}

static inline void	do_read_input(t_action action, t_redirect *redirect)
{
	if (redirect->target == NULL)
		return ;
	dup2(action.pipe_read_input[out], STDIN_FILENO);
	close(action.pipe_read_input[in]);
	close(action.pipe_read_input[out]);
}

static inline void	do_output(t_action action, t_redirect *redirect)
{
	int	fd;

	if (redirect->target == NULL)
		dup2(action.pipe_out, STDOUT_FILENO);
	else
	{
		fd = get_redirect_fd(*redirect);
		if (fd > 0)
		{
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
	}
}

inline void	do_redirects(t_action action)
{
	if (action.redirect_in.type == input)
		do_input(action, &action.redirect_in);
	if (action.redirect_in.type == read_input)
		do_read_input(action, &action.redirect_in);
	if (action.redirect_out.type == output
		|| action.redirect_out.type == output_append)
		do_output(action, &action.redirect_out);
}
