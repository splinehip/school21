/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:06 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/01 18:33:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	monitor(t_args *args, register UINT epme)
{
	register UINT	i;
	register UINT	done_count;
	register UINT	nofp;

	i = 0;
	done_count = 0;
	nofp = args->param.number_of_philosophers;
	while (args->died == false && done_count != nofp)
	{
		pthread_mutex_lock(&args->philo[i].mx_done);
		if (args->philo[i].done)
		{
			args->died = (epme == false || args->philo[i].count_eat != epme);
			done_count++;
		}
		pthread_mutex_unlock(&args->philo[i].mx_done);
		if (args->died == false && done_count != nofp && ++i == nofp)
		{
			i = 0;
			done_count = 0;
		}
	}
	if (args->died)
		printf("%lu\t%i%s\n", args->philo[i].time_stamp, i + 1, MSG_DIED);
}

void	start_threads(void *_args)
{
	register UINT	i;
	t_args			*args;
	struct timeval	stamp;

	args = (t_args *)_args;
	gettimeofday(&stamp, NULL);
	args->param.start_time = stamp.tv_sec * 1000 + stamp.tv_usec / 1000;
	i = 0;
	while (i < args->param.number_of_philosophers)
	{
		pthread_create(&args->threads[i], NULL, (void *)&start_philo,
			(void *)&args->philo[i]);
		pthread_detach(args->threads[i]);
		i += 2;
	}
	usleep(1000);
	i = 1;
	while (i < args->param.number_of_philosophers)
	{
		pthread_create(&args->threads[i], NULL, (void *)&start_philo,
			(void *)&args->philo[i]);
		pthread_detach(args->threads[i]);
		i += 2;
	}
	monitor(args, args->param.each_philosopher_must_eat);
}
