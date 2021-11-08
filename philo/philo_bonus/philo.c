/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:30:43 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/08 13:15:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline ULINT	time_stamp(register const ULINT start)
{
	struct timeval	stamp;

	gettimeofday(&stamp, NULL);
	return ((stamp.tv_sec * 1000 + stamp.tv_usec / 1000) - start);
}

static inline t_bool	take_forks(t_philo *philo)
{
	sem_wait(philo->sems->table);
	sem_wait(philo->sems->forks);
	philo->time_stamp = time_stamp(philo->param->start_time);
	if (write_msg(philo->time_stamp, philo, MSG_TAKEN_FORK,
			SIZE_MSG_TAKEN_FORK) == false)
	{
		sem_post(philo->sems->forks);
		sem_post(philo->sems->table);
		return (false);
	}
	sem_wait(philo->sems->forks);
	sem_post(philo->sems->table);
	philo->time_stamp = time_stamp(philo->param->start_time);
	if (write_msg(philo->time_stamp, philo, MSG_TAKEN_FORK,
			SIZE_MSG_TAKEN_FORK) == false)
	{
		sem_post(philo->sems->forks);
		sem_post(philo->sems->forks);
		return (false);
	}
	return (true);
}

static inline t_bool	eating(t_philo *philo, register UINT epme)
{
	if (write_msg(philo->time_stamp, philo, MSG_EATING,
			SIZE_MSG_EATING) == false)
	{
		sem_post(philo->sems->forks);
		sem_post(philo->sems->forks);
		return (false);
	}
	philo->last_eat = time_stamp(philo->param->start_time);
	usleep(philo->param->time_to_eat);
	sem_post(philo->sems->forks);
	sem_post(philo->sems->forks);
	if (epme)
		philo->count_eat++;
	return (true);
}

static inline t_bool	sleeping(t_philo *philo)
{
	philo->time_stamp = time_stamp(philo->param->start_time);
	if (write_msg(philo->time_stamp, philo,
			MSG_SLEEPING, SIZE_MSG_SLEEPING) == false)
		return (false);
	usleep(philo->param->time_to_sleep);
	return (true);
}

void	start_philo(t_args *args, t_philo *philo)
{
	register UINT	epme;

	epme = philo->param->each_philosopher_must_eat;
	while (true)
	{
		if (take_forks(philo) == false)
			break ;
		if (eating(philo, epme) == false)
			break ;
		if (sleeping(philo) == false)
			break ;
		if (epme && philo->count_eat == epme)
			break ;
		philo->time_stamp = time_stamp(philo->param->start_time);
		if (write_msg(philo->time_stamp, philo,
				MSG_THINKING, SIZE_MSG_THINKING) == false)
			break ;
	}
	exit(exit_status(args, philo));
}
