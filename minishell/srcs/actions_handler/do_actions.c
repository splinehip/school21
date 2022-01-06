/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:28:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/06 15:40:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		while (j < actions->item[i].redirects.len)
			free(actions->item[i].redirects.item[j++].target);
		free(actions->item[i].redirects.item);
		j = 0;
		while (actions->item[i].exec.argv && actions->item[i].exec.argv[j])
			free(actions->item[i].exec.argv[j++]);
		free(actions->item[i].exec.argv);
		free(actions->item[i].exec.path);
		if (i < actions->pipes.len)
			close_pipe(actions->pipes.item[i]);
		i++;
	}
	free(actions->pipes.item);
	free(actions->item);
	unlink(READ_INPUT_FILE);
}

static inline int	open_pipes(t_actions *actions)
{
	int	i;

	i = 0;
	while (i < actions->len)
	{
		if (i < actions->pipes.len && pipe(actions->pipes.item[i].pipe) < 0)
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

int	do_actions(t_actions *actions, char **env)
{
	int		i;
	int		res;
	int		exit_status;

	if (actions == NULL)
		return (unsuccess);
	if (open_pipes(actions) == unsuccess)
		return (unsuccess);
	i = 0;
	res = success;
	exit_status = unsuccess;
	while (i < actions->len)
		res = do_action_run(&actions->item[i++], env);
	i = 0;
	while (i < actions->len)
	{
		if (actions->item[i].pid)
			waitpid(actions->item[i].pid, &exit_status, false);
		i++;
	}
	free_actions(actions);
	if (WIFEXITED(exit_status))
		return (WEXITSTATUS(exit_status));
	return (res);
}
