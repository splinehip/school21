/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:06 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/02 18:10:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline UINT	monitor(t_args *args, register UINT epme, register UINT i)
{
	register UINT	done_count;
	register UINT	nofp;

	done_count = 0;
	nofp = args->param.number_of_philosophers;
	while (args->died == false && done_count != nofp)
	{
		pthread_mutex_lock(&args->philo[i].mx_done);
		if (args->philo[i].done)
		{
			pthread_mutex_lock(&args->mxs.mx_died);
			args->died = (epme == false || args->philo[i].count_eat != epme);
			pthread_mutex_unlock(&args->mxs.mx_died);
			done_count++;
		}
		pthread_mutex_unlock(&args->philo[i].mx_done);
		if (args->died == false && done_count != nofp && ++i == nofp)
		{
			i = 0;
			done_count = 0;
		}
	}
	return (i);
}

static inline void	error(t_args *args, register int i)
{
	register int	j;

	pthread_mutex_lock(&args->mxs.mx_died);
	args->died = true;
	pthread_mutex_unlock(&args->mxs.mx_died);
	j = 0;
	while (j < i)
		pthread_join(args->threads[j++], NULL);
	printf(
		"\n\033[31mStop simulation, philo %u thread creation failed.\033[0m\n\n",
		args->philo[i].id);
}

static inline t_bool	start(t_args *args, register UINT i)
{
	i = 0;
	while (i < args->param.number_of_philosophers)
	{
		if (pthread_create(&args->threads[i], NULL, (void *)&start_philo,
				(void *)&args->philo[i]))
		{
			error(args, i);
			return (true);
		}
		i += 2;
	}
	usleep(1000);
	i = 1;
	while (i < args->param.number_of_philosophers)
	{
		if (pthread_create(&args->threads[i], NULL, (void *)&start_philo,
				(void *)&args->philo[i]))
		{
			error(args, i);
			return (true);
		}
		i += 2;
	}
	return (false);
}

t_bool	start_threads(void *_args)
{
	register UINT	i;
	register UINT	j;
	t_args			*args;
	struct timeval	stamp;

	args = (t_args *)_args;
	gettimeofday(&stamp, NULL);
	args->param.start_time = stamp.tv_sec * 1000 + stamp.tv_usec / 1000;
	if (start(args, 0))
		return (true);
	i = monitor(args, args->param.each_philosopher_must_eat, 0);
	j = 0;
	while (j < args->param.number_of_philosophers)
		pthread_join(args->threads[j++], NULL);
	if (args->died)
		printf("%lu\t%i%s\n", args->philo[i].time_stamp, i + 1, MSG_DIED);
	return (false);
}
