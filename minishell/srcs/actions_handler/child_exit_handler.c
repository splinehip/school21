/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_exit_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:00:18 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/14 11:21:43 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include "bool.h"
#include "builtins.h"
#include "actions_handler.h"

static inline void	do_wait(t_actions *actions)
{
	int	i;

	i = 0;
	while (i < actions->len)
	{
		if (actions->item[i].pid)
			waitpid(actions->item[i].pid, NULL, false);
		i++;
	}
}

inline void	child_exit_handler(t_actions *actions, int *exit_status)
{
	if (actions->item[actions->len - 1].pid)
	{
		waitpid(actions->item[actions->len - 1].pid, exit_status, false);
		do_wait(actions);
	}
	else
		do_wait(actions);
}
