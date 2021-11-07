/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:08:33 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/07 19:14:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	free_mem(t_args *args)
{
	free(args->philo);
	free(args->pids);
	free(args->exit_status);
	sem_close(args->sems.table);
	sem_close(args->sems.forks);
	sem_close(args->sems.s_stdout);
}

__always_inline int	exit_status(t_args *args, t_philo *philo)
{
	if (philo->param->each_philosopher_must_eat == false
		|| philo->count_eat != philo->param->each_philosopher_must_eat)
	{
		sem_wait(args->sems.s_stdout);
		printf("%lu\t%i%s\n", philo->time_stamp, philo->id, MSG_DIED);
		free_mem(args);
		return (true);
	}
	free_mem(args);
	return (false);
}
