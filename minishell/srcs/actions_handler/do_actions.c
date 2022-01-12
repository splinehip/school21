/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:28:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/12 15:27:03 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "actions_handler.h"
#include "minishell.h"

static inline void	close_pipe(t_pipe item)
{
	close(item.pipe[0]);
	close(item.pipe[1]);
}

static inline void	free_actions(t_actions *actions)
{
	int	i;
	int	j;

	i = 0;
	while (actions && i < actions->len)
	{
		j = 0;
		while (actions->item[i].exec.argv && actions->item[i].exec.argv[j])
			free(actions->item[i].exec.argv[j++]);
		free(actions->item[i].exec.argv);
		free(actions->item[i].exec.path);
		free(actions->item[i].redirect_in.target);
		free(actions->item[i].redirect_out.target);
		if (i < actions->pipes.len && !g_interrupt)
			close_pipe(actions->pipes.item[i]);
		i++;
	}
	free(actions->pipes.item);
	free(actions->item);
}

static inline int	open_pipes(t_actions *actions)
{
	int	i;
	int	pipe_read_input;

	i = 0;
	pipe_read_input = 0;
	while (i < actions->len)
	{
		if (actions->item[i].redirect_in.type == read_input)
			pipe_read_input = pipe(actions->item[i].pipe_read_input);
		if ((i < actions->pipes.len && pipe(actions->pipes.item[i].pipe) < 0)
			|| pipe_read_input < 0)
		{
			while (--i >= 0)
				close_pipe(actions->pipes.item[i]);
			free_actions(actions);
			print_err(MSG_ERR_PIPE, NULL, 0);
			return (unsuccess);
		}
		if (i > 0)
			actions->item[i].pipe_in = actions->pipes.item[i - 1].pipe[0];
		if (i < actions->pipes.len)
			actions->item[i].pipe_out = actions->pipes.item[i].pipe[1];
		i++;
	}
	return (success);
}

static inline int	do_run(t_actions *actions, char ***env)
{
	int		i;
	int		res;
	int		exit_status;

	i = 0;
	res = success;
	exit_status = unsuccess;
	while (i < actions->len)
		res = do_action_run(&actions->item[i++], env);
	child_exit_handler(actions, &exit_status, res);
	if (actions->item[actions->len - 1].pid)
	{
		free_actions(actions);
		if (WIFEXITED(exit_status))
			return (WEXITSTATUS(exit_status));
		else if (WIFSIGNALED(exit_status))
			return (WTERMSIG(exit_status));
	}
	free_actions(actions);
	return (res);
}

int	do_actions(t_actions *actions, char ***env)
{
	if (actions == NULL)
		return (unsuccess);
	if (g_interrupt)
	{
		free_actions(actions);
		return (130);
	}
	if (open_pipes(actions) == unsuccess)
		return (unsuccess);
	return (do_run(actions, env));
}
