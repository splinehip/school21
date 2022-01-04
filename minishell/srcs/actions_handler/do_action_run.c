/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:03:05 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/04 16:12:10 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "actions_handler.h"

static inline int	do_action_builtin(t_action *action, char **env)
{
	if (action->type == exit_built)
		return (do_exit(*action, env));
	else if (action->type == pwd)
		return (do_pwd(env));
	return (success);
}

static inline int	do_action_exec(t_action *action, char **env)
{
	action->pid = fork();
	if (action->pid == success)
	{
		if (is_valid_action_path(action, env) == false)
			exit(127);
		do_redirects(*action, env);
		if (action->exec.path)
			execve(action->exec.path, action->exec.argv, env);
		execve(action->exec.argv[0], action->exec.argv, env);
	}
	else if (action->pid < 0)
	{
		perror("minishell");
		close(action->pipe_in);
		close(action->pipe_out);
		action->pid = 0;
		return (unsuccess);
	}
	if (action->pipe_out)
		close(action->pipe_out);
	return (success);
}

inline int	do_action_run(t_action *action, char **env)
{
	if (action->type == execute)
		return (do_action_exec(action, env));
	else
		return (do_action_builtin(action, env));
}
