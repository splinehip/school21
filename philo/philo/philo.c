/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:30:43 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/02 13:14:32 by cflorind         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->mxs->forks[philo->fork_1]);
	philo->time_stamp = time_stamp(philo->param->start_time);
	if (write_msg(philo->time_stamp, philo, MSG_TAKEN_FORK,
			SIZE_MSG_TAKEN_FORK) == false)
	{
		pthread_mutex_unlock(&philo->mxs->forks[philo->fork_1]);
		return (false);
	}
	pthread_mutex_lock(&philo->mxs->forks[philo->fork_2]);
	philo->time_stamp = time_stamp(philo->param->start_time);
	return (true);
}

static inline t_bool	eating(t_philo *philo, register UINT epme)
{
	if (write_msg(philo->time_stamp, philo, MSG_EATING,
			SIZE_MSG_EATING) == false)
	{
		pthread_mutex_unlock(&philo->mxs->forks[philo->fork_2]);
		pthread_mutex_unlock(&philo->mxs->forks[philo->fork_1]);
		return (false);
	}
	philo->last_eat = time_stamp(philo->param->start_time);
	usleep(philo->param->time_to_eat);
	pthread_mutex_unlock(&philo->mxs->forks[philo->fork_2]);
	pthread_mutex_unlock(&philo->mxs->forks[philo->fork_1]);
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

void	start_philo(void *args)
{
	t_philo			*philo;
	register UINT	epme;

	philo = (t_philo *)args;
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
		if (write_msg(time_stamp(philo->param->start_time), philo,
				MSG_THINKING, SIZE_MSG_THINKING) == false)
			break ;
		if (time_stamp(philo->param->start_time) - philo->last_eat
			<= philo->param->time_to_die / 10 * 8)
			usleep(500);
	}
	pthread_mutex_lock(&philo->mx_done);
	philo->done = true;
	pthread_mutex_unlock(&philo->mx_done);
}
