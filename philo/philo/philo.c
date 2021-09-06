/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:30:43 by cflorind          #+#    #+#             */
/*   Updated: 2021/09/06 21:13:41 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	eating(t_philo *philo, UINT stamp)
{
	if (*philo->died != 0
		|| stamp - philo->last_eat > philo->param->time_to_die)
	{
		pthread_mutex_unlock(&philo->table->mx_forks[philo->fork_l]);
		pthread_mutex_unlock(&philo->table->mx_forks[philo->fork_r]);
		if (*philo->died == 0)
		{
			*philo->died = 1;
			pthread_mutex_lock(philo->mx_print);
			printf("%u ms %i is died\n", stamp, philo->id);
			pthread_mutex_unlock(philo->mx_print);
		}
	}
	else
	{
		usleep(philo->param->time_to_eat);
		pthread_mutex_unlock(&philo->table->mx_forks[philo->fork_l]);
		pthread_mutex_unlock(&philo->table->mx_forks[philo->fork_r]);
		pthread_mutex_lock(philo->mx_print);
		printf("%u ms %i has taken a forks\n%u ms %i is eating\n",
			stamp, philo->id, stamp, philo->id);
		pthread_mutex_unlock(philo->mx_print);
		philo->last_eat = stamp + (philo->param->time_to_eat / 1000);
		philo->count_eat += 1;
	}
}

static inline void	sleeping(t_philo *philo)
{
	if (*philo->died == 0)
	{
		pthread_mutex_lock(philo->mx_print);
		printf("%u ms %i is sleeping\n",
			time_stamp(&philo->param->start_time), philo->id);
		pthread_mutex_unlock(philo->mx_print);
		usleep(philo->param->time_to_sleep);
	}
}

static inline void	thinking(t_philo *philo)
{
	if (*philo->died == 0)
	{
		pthread_mutex_lock(philo->mx_print);
		printf("%u ms %i is thinking\n",
			time_stamp(&philo->param->start_time), philo->id);
		pthread_mutex_unlock(philo->mx_print);
	}
}

void	start_philo(void *args)
{
	UINT	stamp;
	t_philo	*philo;

	philo = (t_philo *)args;
	while ((*philo->died == 0 && philo->param->each_philosopher_must_eat == 0)
		|| (philo->param->each_philosopher_must_eat > 0
			&& philo->count_eat != philo->param->each_philosopher_must_eat))
	{
		pthread_mutex_lock(&philo->table->mx_table);
		pthread_mutex_lock(&philo->table->mx_forks[philo->fork_l]);
		pthread_mutex_lock(&philo->table->mx_forks[philo->fork_r]);
		pthread_mutex_unlock(&philo->table->mx_table);
		stamp = time_stamp(&philo->param->start_time);
		eating(philo, stamp);
		sleeping(philo);
		thinking(philo);
	}
}
