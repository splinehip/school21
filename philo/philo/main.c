/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:46:27 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/19 13:44:17 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	init_args(t_args *args)
{
	UINT	i;

	args->threads = malloc(
			args->param.number_of_philosophers * sizeof(pthread_t));
	args->philo = malloc(args->param.number_of_philosophers * sizeof(t_philo));
	args->mxs.forks = malloc(args->param.number_of_philosophers
			* sizeof(pthread_mutex_t));
	args->eated_count = 0;
	args->stop = false;
	i = 0;
	while (i < args->param.number_of_philosophers)
		pthread_mutex_init(&args->mxs.forks[i++], NULL);
	pthread_mutex_init(&args->mxs.stop, NULL);
	pthread_mutex_init(&args->mxs.eated_count, NULL);
}

static inline void	init_forks(t_args *args, UINT i)
{
	if (i == args->param.number_of_philosophers - 1)
	{
		args->philo[i].fork_l = 0;
		args->philo[i].fork_r = i;
	}
	else
	{
		args->philo[i].fork_l = i;
		args->philo[i].fork_r = i + 1;
	}
}

static inline void	init_philosophers(t_args *args)
{
	UINT	i;

	i = 0;
	while (i < args->param.number_of_philosophers)
	{
		args->philo[i].id = i + 1;
		args->philo[i].last_eat = 0;
		args->philo[i].count_eat = 0;
		args->philo[i].died = 0;
		args->philo[i].param = &args->param;
		args->philo[i].mxs = &args->mxs;
		args->philo[i].eated_count = &args->eated_count;
		args->philo[i].stop = &args->stop;
		init_forks(args, i++);
	}
}

int	main(int argc, char **argv)
{
	t_args		args;
	pthread_t	main;

	gettimeofday(&args.param.start_time, NULL);
	if (argv_handler(argc, argv, &args.param))
		return (1);
	init_args(&args);
	init_philosophers(&args);
	pthread_create(&main, NULL, (void *)&start_threads, (void *)&args);
	pthread_join(main, NULL);
	if (args.stop == false && args.param.each_philosopher_must_eat > 0)
		printf("\nStop simulation, %u philosophers eated %u times.\n\n",
			args.eated_count, args.param.each_philosopher_must_eat);
	if (args.stop)
		printf("\nStop simulation, philosopher died.\n\n");
	free(args.threads);
	free(args.philo);
	free(args.mxs.forks);
	return (0);
}
