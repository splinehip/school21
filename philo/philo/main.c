/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:46:27 by cflorind          #+#    #+#             */
/*   Updated: 2021/09/02 00:11:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline long unsigned int	time_stamp(const struct timeval *start)
{
	struct timeval	stamp;

	gettimeofday(&stamp, NULL);
	return ((stamp.tv_usec - start->tv_usec) / 1000);
}

static void	test_1(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("thread: %i, time_stamp: %ld\n", philo->pid,
		time_stamp(philo->start_time));
}

int	main(int argc, char **argv)
{
	int				i;
	struct timeval	start_time;
	t_args			args;
	t_philo			*philo;
	pthread_t		*threads;

	gettimeofday(&start_time, NULL);
	if (argv_handler(argc, argv, &args))
		return (-1);
	philo = malloc(args.number_of_philosophers * sizeof(t_philo));
	threads = malloc(args.number_of_philosophers * sizeof(pthread_t));
	i = 0;
	while (i < args.number_of_philosophers)
	{
		philo[i].pid = i;
		philo[i].args = &args;
		philo[i].start_time = &start_time;
		pthread_create(&threads[i], NULL, (void *)&test_1, (void *)&philo[i]);
		pthread_join(threads[i++], NULL);
	}
	free(threads);
	free(philo);
	return (0);
}
