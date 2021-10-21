/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:06 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/21 14:08:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	monitor_stop(t_args *args)
{
	UINT	i;

	i = 0;
	while (true)
	{
		pthread_mutex_lock(&args->mxs.stop);
		args->stop = args->philo[i++].died;
		pthread_mutex_unlock(&args->mxs.stop);
		if (args->stop)
		{
			usleep(1000);
			printf("%u\t%i is died\n", args->philo[i - 1].current_time, i);
			break ;
		}
		if (i == args->param.number_of_philosophers)
			i = 0;
	}
}

static inline void	monitor_stop_and_eat(t_args *args)
{
	UINT	i;

	i = 0;
	while (true)
	{
		pthread_mutex_lock(&args->mxs.stop);
		args->stop = args->philo[i++].died;
		pthread_mutex_unlock(&args->mxs.stop);
		if (args->stop)
		{
			usleep(1000);
			printf("%u\t%i is died\n", args->philo[i - 1].current_time, i);
			break ;
		}
		pthread_mutex_lock(&args->mxs.eated_count);
		if (args->eated_count == args->param.number_of_philosophers)
		{
			pthread_mutex_unlock(&args->mxs.eated_count);
			break ;
		}
		pthread_mutex_unlock(&args->mxs.eated_count);
		if (i == args->param.number_of_philosophers)
			i = 0;
	}
}

void	start_threads(void *_args)
{
	UINT		i;
	t_args		*args;

	args = (t_args *)_args;
	i = 0;
	while (i < args->param.number_of_philosophers)
	{
		pthread_create(&args->threads[i], NULL, (void *)&start_philo,
			(void *)&args->philo[i]);
		i++;
	}
	if (args->param.each_philosopher_must_eat == 0)
		monitor_stop(args);
	else
		monitor_stop_and_eat(args);
	i = 0;
	while (i < args->param.number_of_philosophers)
		pthread_join(args->threads[i++], NULL);
}
