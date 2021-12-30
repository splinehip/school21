/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:28:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/30 15:49:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "actions_handler.h"

static inline void	free_actions(t_actions *actions, int *pipes)
{
	int	i;
	int	j;

	i = 0;
	while (actions && actions[i].end == false)
	{
		j = 0;
		while (actions[i].args.redirect
			&& actions[i].args.redirect[j].end == false)
			free(actions[i].args.redirect[j++].target);
		free(actions[i].args.redirect);
		j = 0;
		while (actions[i].args.argv && actions[i].args.argv[j])
			free(actions[i].args.argv[j++]);
		free(actions[i].args.argv);
		free(actions[i].args.path);
		i++;
	}
	free(actions);
	if (pipes)
	{
		close(pipes[0]);
		close(pipes[1]);
	}
}

static inline int	do_action_run(t_actions *action, int *pipes, char **env)
{
	char	*path;
	pid_t	pid;

	if (is_valid_action_path(action, env) == false)
		return (127);
	if (action->args.path)
		path = action->args.path;
	else
		path = action->args.argv[0];
	pid = fork();
	if (pid == success)
	{
		do_redirects(action->args.redirect, pipes, env);
		close(pipes[0]);
		close(pipes[1]);
		execve(path, action->args.argv, env);
	}
	else if (pid < 0)
	{
		perror("minishell");
		return (unsuccess);
	}
	return (success);
}

static inline int	do_action_builtin(
	t_actions *action, int *pipes, char **env)
{
	int	res;

	(void)pipes;
	res = success;
	if (action->type == exit_built)
		return (do_exit(*action, env));
	else if (action->type == pwd)
		return (do_pwd(env));
	return (res);
}

static inline int	do_init(t_actions *actions, int *pipes)
{
	if (actions == NULL)
		return (unsuccess);
	if (pipe(pipes) < 0)
	{
		free_actions(actions, NULL);
		printf(MSG_ERR_PIPE);
		return (unsuccess);
	}
	return (success);
}

int	do_actions(t_actions *actions, char **env)
{
	int	i;
	int	res;
	int	pipes[2];
	int	do_wait;

	if (do_init(actions, &pipes[0]) == unsuccess)
		return (unsuccess);
	i = 0;
	res = success;
	do_wait = unsuccess;
	while (actions[i].end == false)
	{
		actions[i].args.path = NULL;
		if (actions[i].type == execute)
			do_wait = do_action_run(&actions[i], &pipes[0], env);
		else
			res = do_action_builtin(&actions[i], &pipes[0], env);
		i++;
	}
	while (do_wait == success)
		if (waitpid(-1, &res, WNOHANG))
			break ;
	free_actions(actions, &pipes[0]);
	return (res);
}
