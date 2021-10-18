/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:06 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/18 23:28:11 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	start_serial(pthread_t *threads, t_args *args)
{
	UINT	i;

	i = 0;
	while (i < args->param.number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, (void *)&start_philo,
			(void *)&args->philo[i]);
		i++;
	}
}

static inline void	start_differ(pthread_t *threads, t_args *args)
{
	UINT	i;
	UINT	k;

	if (args->param.time_to_eat * 3 > args->param.time_to_die * 1000)
		k = args->param.time_to_eat * 3 - args->param.time_to_die * 1000;
	else
		k = args->param.time_to_die * 1000 - args->param.time_to_eat * 3;
	if (k / args->param.number_of_philosophers < 10000)
		k = 0;
	if (k > 10000)
		k = 10000;
	i = 0;
	while (i < args->param.number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, (void *)&start_philo,
			(void *)&args->philo[i]);
		i += 2;
		usleep(k);
	}
	i = 1;
	while (i < args->param.number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, (void *)&start_philo,
			(void *)&args->philo[i]);
		i += 2;
	}
}

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
			break ;
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
			break ;
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

void	start_threads(void *targs)
{
	UINT		i;
	t_args		*args;
	pthread_t	*threads;

	args = ((t_targs *)targs)->args;
	threads = ((t_targs *)targs)->threads;
	if (args->param.number_of_philosophers % 2 == 0)
		start_serial(threads, args);
	else
		start_differ(threads, args);
	if (args->param.each_philosopher_must_eat == 0)
		monitor_stop(args);
	else
		monitor_stop_and_eat(args);
	i = 0;
	while (i < args->param.number_of_philosophers)
		pthread_join(threads[i++], NULL);
}
