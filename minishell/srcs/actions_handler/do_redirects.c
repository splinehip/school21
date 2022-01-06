/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:48:54 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/06 23:55:06 by cflorind         ###   ########.fr       */
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

static inline void	do_read_input(int *read_input_res, char *target, char **env)
{
	int		fd;
	char	*parsed_res;
	char	*readline_res;

	fd = open(READ_INPUT_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd < 0)
		perror(MSG_PROG_NAME);
	while (fd)
	{
		readline_res = readline("> ");
		if (ft_strncmp(readline_res, target, ft_strlen(target)) == success)
		{
			free(readline_res);
			*read_input_res = true;
			break ;
		}
		parsed_res = parse_cmd(readline_res, env, false);
		if (parsed_res)
			ft_putendl_fd(parsed_res, fd);
		free(parsed_res);
		free(readline_res);
	}
	close(fd);
}

static inline void	do_input(
	t_action action, t_redirect *redirect, int *read_input_res, char **env)
{
	int	i;
	int	fd;

	if (redirect->type == input && redirect->target == NULL)
	{
		i = 0;
		fd = 0;
		while (action.redirects.len > 1 && ++i < action.redirects.len && !fd)
			if (action.redirects.item[i].type == input
				|| action.redirects.item[i].type == read_input)
				fd++;
		if (fd == false)
			dup2(action.pipe_in, 0);
	}
	else if (redirect->type == input)
	{
		fd = get_redirect_fd(*redirect);
		if (fd > 0)
			dup2(fd, 0);
		close(fd);
	}
	else if (redirect->type == read_input)
		do_read_input(read_input_res, redirect->target, env);
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
	int	read_input_res;

	i = 0;
	read_input_res = false;
	while (i < action.redirects.len)
	{
		if (action.redirects.item[i].type == input
			|| action.redirects.item[i].type == read_input)
		{
			read_input_res = false;
			do_input(action, &action.redirects.item[i], &read_input_res, env);
		}
		if (action.redirects.item[i].type == output
			|| action.redirects.item[i].type == output_append)
			do_output(action, &action.redirects.item[i]);
		i++;
	}
	if (read_input_res)
		do_read_input_redirect();
}
