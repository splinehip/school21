/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:48:54 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/06 15:41:20 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <sys/types.h>
#include <sys/stat.h>
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

static inline void	do_read_input(char **read_input_res, char *target)
{
	char	*tmp;
	char	*readline_res;

	while (true)
	{
		readline_res = readline(">");
		if (ft_strncmp(readline_res, target, ft_strlen(tmp)) == success)
		{
			free(tmp);
			return ;
		}
		if (readline_res)
		{
			tmp = readline_res;
			readline_res = ft_strljoinchr(readline_res, endl);
			free(tmp);
		}
		tmp = *read_input_res;
		*read_input_res = ft_strjoin(*read_input_res, readline_res);
		free(tmp);
	}
}

static inline void	do_input(
	t_action action, t_redirect *redirect, char **read_input_res)
{
	int		fd;

	if (redirect->target == NULL)
		dup2(action.pipe_in, 0);
	else if (redirect->type == input)
	{
		fd = get_redirect_fd(*redirect);
		if (fd > 0)
		{
			dup2(fd, 0);
			close(fd);
		}
	}
	else if (redirect->type == read_input)
		do_read_input(read_input_res, redirect->target);
}

static inline void	do_output(t_action action, t_redirect *redirect)
{
	int	fd;

	if (redirect->target == NULL)
		dup2(action.pipe_out, 1);
	else
	{
		fd = get_redirect_fd(*redirect);
		if (fd > 0)
		{
			dup2(fd, 1);
			close(fd);
		}
	}
}

static inline void	do_write_read_input_res(char *read_input_res, char **env)
{
	int		fd;

	(void)env;
	read_input_res = parse_cmd(read_input_res, env, false);
	if (read_input_res)
	{
		fd = open(READ_INPUT_FILE, O_CREAT | O_TRUNC | O_WRONLY);
		if (fd > 0)
		{
			ft_putstr_fd(read_input_res, fd);
			close(fd);
			fd = open(READ_INPUT_FILE, O_RDONLY);
			if (fd > 0)
			{
				dup2(fd, 0);
				close(fd);
			}
			else
				perror(MSG_PROG_NAME);
		}
		else
			perror(MSG_PROG_NAME);
		free(read_input_res);
	}
}

inline void	do_redirects(t_action action, char **env)
{
	int		i;
	char	*read_input_res;

	i = 0;
	read_input_res = NULL;
	while (i < action.redirects.len)
	{
		if (action.redirects.item[i].type == input
			|| action.redirects.item[i].type == read_input)
		{
			if (read_input_res)
			{
				free(read_input_res);
				read_input_res = NULL;
			}
			do_input(action, &action.redirects.item[i], &read_input_res);
		}
		if (action.redirects.item[i].type == output
			|| action.redirects.item[i].type == output_append)
			do_output(action, &action.redirects.item[i]);
		i++;
	}
	if (read_input_res)
		do_write_read_input_res(read_input_res, env);
	free(read_input_res);
}
