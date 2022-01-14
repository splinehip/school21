/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:03:05 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/14 15:26:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "libft.h"
#include "bool.h"
#include "mesages.h"
#include "error_msgs.h"
#include "builtins.h"
#include "actions_handler.h"
#include "minishell.h"

static inline int	do_action_builtin(t_action *action, char ***env)
{
	if (action->type == exit_built)
		return (do_exit(*action, env));
	else if (action->type == pwd)
		return (do_pwd(*action, *env));
	else if (action->type == cd)
		return (do_cd(*action, env));
	else if (action->type == echo)
		return (do_echo(*action));
	else if (action->type == unset)
		return (do_unset(*action, env));
	else if (action->type == export)
		return (do_export(*action, env));
	else if (action->type == env_built)
		return (do_env(*action, *env));
	return (success);
}

static inline void	do_update_shlvl(char ***env)
{
	int		res;
	char	*tmp;

	tmp = get_env_value("SHLVL", *env);
	if (tmp == NULL)
		res = 0;
	else
		res = ft_atoi(tmp);
	res++;
	free(tmp);
	tmp = ft_itoa(res);
	if (tmp)
		set_env("SHLVL", tmp, env);
	free(tmp);
}

static inline void	do_finish_exec(t_action *action)
{
	if (action->pipe_out)
		close(action->pipe_out);
	if (action->pipe_read_input[in])
	{
		if (action->redirect_in.target)
			ft_putstr_fd(action->redirect_in.target,
				action->pipe_read_input[in]);
		close(action->pipe_read_input[in]);
		close(action->pipe_read_input[out]);
	}
	if (action->pid > 0
		&& ft_strnstr(*action->exec.argv, SHBIN, ft_strlen(*action->exec.argv)))
		set_signals(2, 0);
}

static inline int	do_action_exec(t_action *action, char ***env)
{
	action->pid = fork();
	if (action->pid == success)
	{
		if (is_valid_action_path(action, *env) == false)
			exit(127);
		do_update_shlvl(env);
		do_redirects(*action);
		if (action->pipe_in)
			close(action->pipe_in);
		if (action->pipe_out)
			close(action->pipe_out);
		if (action->exec.path)
			execve(action->exec.path, action->exec.argv, *env);
		execve(action->exec.argv[0], action->exec.argv, *env);
	}
	else if (action->pid < 0)
	{
		perror(MSG_PROG_NAME);
		action->pid = 0;
		return (unsuccess);
	}
	do_finish_exec(action);
	return (success);
}

inline int	do_action_run(t_action *action, char ***env)
{
	if (action->type == execute)
		return (do_action_exec(action, env));
	else
		return (do_action_builtin(action, env));
}
