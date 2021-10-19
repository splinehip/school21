/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:30:43 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/19 18:47:30 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline t_bool	stop_is_false(t_philo *philo)
{
	t_bool	ret;

	pthread_mutex_lock(&philo->mxs->stop);
	ret = *philo->stop;
	pthread_mutex_unlock(&philo->mxs->stop);
	return (ret == false);
}

static inline void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mxs->stop);
	philo->died = philo->current_time - philo->last_eat
		> philo->param->time_to_die;
	pthread_mutex_unlock(&philo->mxs->stop);
	if (stop_is_false(philo) == false || philo->died)
	{
		pthread_mutex_unlock(&philo->mxs->forks[philo->fork_r]);
		pthread_mutex_unlock(&philo->mxs->forks[philo->fork_l]);
	}
	else
	{
		philo->last_eat = philo->current_time;
		printf("%u\t%i has taken a forks\n%u\t%i is eating\n",
			philo->last_eat, philo->id, philo->last_eat, philo->id);
		usleep(philo->param->time_to_eat);
		pthread_mutex_unlock(&philo->mxs->forks[philo->fork_r]);
		pthread_mutex_unlock(&philo->mxs->forks[philo->fork_l]);
		philo->count_eat += 1;
	}
}

static inline t_bool	stop_eating(t_philo *philo)
{
	if (stop_is_false(philo) && philo->param->each_philosopher_must_eat > 0
		&& philo->count_eat == philo->param->each_philosopher_must_eat)
	{
		pthread_mutex_lock(&philo->mxs->eated_count);
		*philo->eated_count += 1;
		pthread_mutex_unlock(&philo->mxs->eated_count);
		return (true);
	}
	return (false);
}

static inline void	please_wait(t_philo *philo)
{
	if (time_stamp(&philo->param->start_time) - philo->last_eat
		< philo->param->time_to_die - 5)
		usleep((philo->param->time_to_die
				- (time_stamp(&philo->param->start_time) - philo->last_eat) - 5)
			* 1000);
}

void	start_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (stop_is_false(philo))
	{
		pthread_mutex_lock(&philo->mxs->forks[philo->fork_l]);
		pthread_mutex_lock(&philo->mxs->forks[philo->fork_r]);
		philo->current_time = time_stamp(&philo->param->start_time);
		eating(philo);
		if (stop_eating(philo))
			break ;
		if (stop_is_false(philo))
		{
			printf("%u\t%i is sleeping\n",
				time_stamp(&philo->param->start_time), philo->id);
			usleep(philo->param->time_to_sleep);
			if (stop_is_false(philo))
			{
				printf("%u\t%i is thinking\n",
					time_stamp(&philo->param->start_time), philo->id);
				please_wait(philo);
			}
		}
	}
}
