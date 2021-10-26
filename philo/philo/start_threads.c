/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:06 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/26 16:45:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline t_bool	eated_count(t_args *args, register UINT epme,
	register UINT i)
{
	pthread_mutex_lock(&args->philo[i].mx_eated_count);
	if (args->philo[i].count_eat == epme)
		args->eated_count++;
	pthread_mutex_unlock(&args->philo[i].mx_eated_count);
	return (args->eated_count == args->param.number_of_philosophers);
}

static inline void	monitor(t_args *args, register UINT epme)
{
	register UINT	i;
	register UINT	nofp;

	i = 0;
	nofp = args->param.number_of_philosophers;
	while (true)
	{
		pthread_mutex_lock(&args->philo[i].mx_died);
		if (args->philo[i].died)
		{
			pthread_mutex_unlock(&args->philo[i].mx_died);
			pthread_mutex_lock(&args->mxs.stop);
			args->stop = true;
			pthread_mutex_unlock(&args->mxs.stop);
			break ;
		}
		pthread_mutex_unlock(&args->philo[i].mx_died);
		if (epme && eated_count(args, epme, i))
			break ;
		if (++i == nofp)
			i = 0;
	}
	if (args->stop)
		printf("%u\t%i%s", args->philo[i].time_stamp, i + 1, MSG_DIED);
}

void	start_threads(void *_args)
{
	register UINT	i;
	t_args			*args;

	args = (t_args *)_args;
	i = 0;
	gettimeofday(&args->param.start_time, NULL);
	while (i < args->param.number_of_philosophers)
	{
		pthread_mutex_lock(&args->mxs.start);
		pthread_create(&args->threads[i], NULL, (void *)&start_philo,
			(void *)&args->philo[i]);
		i++;
	}
	monitor(args, args->param.each_philosopher_must_eat);
	i = 0;
	while (i < args->param.number_of_philosophers)
		pthread_join(args->threads[i++], NULL);
}
