/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:06 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/07 18:32:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	monitor(t_args *args, register UINT i)
{
	register UINT	done_count;
	register UINT	nofp;

	done_count = 0;
	nofp = args->param.number_of_philosophers;
	while (args->died == false && done_count != nofp)
	{
		waitpid(args->pids[i], &args->exit_status[i], WNOHANG);
		if (args->exit_status[i] > 0)
		{
			args->died = true;
			i = 0;
			while (i < args->param.number_of_philosophers)
				kill(args->pids[i++], SIGKILL);
			return ;
		}
		else if (args->exit_status[i] == false)
			done_count++;
		if (args->died == false && done_count != nofp && ++i == nofp)
		{
			i = 0;
			done_count = 0;
		}
	}
}

static inline void	error(t_args *args, register UINT i)
{
	register UINT	j;

	j = 0;
	while (j < i)
		kill(args->pids[j++], SIGKILL);
	printf(
		"\n\033[31mStop simulation, philo %u process creation failed.\033[0m\n\n",
		args->philo[i].id);
}

static inline t_bool	start(t_args *args, register UINT i)
{
	i = 0;
	while (i < args->param.number_of_philosophers)
	{
		args->pids[i] = fork();
		if (args->pids[i] == 0)
			start_philo(args, &args->philo[i]);
		else if (args->pids[i] < 0)
		{
			error(args, i);
			return (true);
		}
		i++;
	}
	return (false);
}

t_bool	start_processes(t_args *args)
{
	struct timeval	stamp;

	gettimeofday(&stamp, NULL);
	args->param.start_time = stamp.tv_sec * 1000 + stamp.tv_usec / 1000;
	if (start(args, 0))
		return (true);
	monitor(args, 0);
	return (false);
}
