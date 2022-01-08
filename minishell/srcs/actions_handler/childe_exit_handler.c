/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childe_exit_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:00:18 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/08 23:33:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include "bool.h"
#include "builtins.h"
#include "actions_handler.h"

static inline void	do_wait_or_kill(t_actions *actions, int status)
{
	int	i;

	i = 0;
	while (i < actions->len)
	{
		if (actions->item[i].pid)
		{
			if (status != success)
				kill(actions->item[i].pid, SIGKILL);
			else
				waitpid(actions->item[i].pid, NULL, false);
		}
		i++;
	}
}

inline void	childe_exit_handler(t_actions *actions, int *exit_status, int res)
{
	if (actions->item[actions->len - 1].pid)
	{
		waitpid(actions->item[actions->len - 1].pid, exit_status, false);
		if (WIFEXITED(*exit_status))
			do_wait_or_kill(actions, WEXITSTATUS(*exit_status));
		else if (WIFSIGNALED(*exit_status))
			do_wait_or_kill(actions, WTERMSIG(*exit_status));
	}
	else
		do_wait_or_kill(actions, res);
}
