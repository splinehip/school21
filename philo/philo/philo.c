/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:30:43 by cflorind          #+#    #+#             */
/*   Updated: 2021/09/12 11:13:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	eating(t_philo *philo)
{
	if (*philo->died != 0
		|| time_stamp(&philo->param->start_time)
		- philo->last_eat > philo->param->time_to_die)
	{
		pthread_mutex_unlock(&philo->table->mx_forks[philo->fork_r]);
		pthread_mutex_unlock(&philo->table->mx_forks[philo->fork_l]);
		if (*philo->died == 0)
		{
			*philo->died = 1;
			printf("%u %i is died\n", time_stamp(&philo->param->start_time),
				philo->id);
		}
	}
	else
	{
		philo->last_eat = time_stamp(&philo->param->start_time);
		usleep(philo->param->time_to_eat);
		pthread_mutex_unlock(&philo->table->mx_forks[philo->fork_r]);
		pthread_mutex_unlock(&philo->table->mx_forks[philo->fork_l]);
		printf("%u %i has taken a forks\n%u %i is eating\n",
			philo->last_eat, philo->id, philo->last_eat, philo->id);
		philo->count_eat += 1;
	}
}

void	start_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while ((*philo->died == 0 && philo->param->each_philosopher_must_eat == 0)
		|| (*philo->died == 0 && philo->param->each_philosopher_must_eat > 0
			&& philo->count_eat != philo->param->each_philosopher_must_eat))
	{
		pthread_mutex_lock(&philo->table->mx_forks[philo->fork_l]);
		pthread_mutex_lock(&philo->table->mx_forks[philo->fork_r]);
		eating(philo);
		if (*philo->died == 0)
		{
			printf("%u %i is sleeping\n",
				time_stamp(&philo->param->start_time), philo->id);
			usleep(philo->param->time_to_sleep);
		}
		if (*philo->died == 0)
			printf("%u %i is thinking\n",
				time_stamp(&philo->param->start_time), philo->id);
	}
}
