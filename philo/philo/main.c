/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:46:27 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/26 13:42:52 by cflorind         ###   ########.fr       */
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
	pthread_mutex_init(&args->mxs.start, NULL);
	pthread_mutex_init(&args->mxs.stop, NULL);
	pthread_mutex_init(&args->mxs.mx_stdout, NULL);
}

static inline void	init_forks(t_args *args, UINT i)
{
	if (i == 0)
	{
		args->philo[i].fork_1 = i;
		args->philo[i].fork_2 = args->param.number_of_philosophers - 1;
	}
	else
	{
		args->philo[i].fork_1 = i - 1;
		args->philo[i].fork_2 = i;
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
		args->philo[i].stop = &args->stop;
		pthread_mutex_init(&args->philo[i].mx_died, NULL);
		pthread_mutex_init(&args->philo[i].mx_eated_count, NULL);
		init_forks(args, i++);
	}
}

int	main(int argc, char **argv)
{
	t_args		args;
	pthread_t	main;

	if (argv_handler(argc, argv, &args.param))
		return (1);
	init_args(&args);
	init_philosophers(&args);
	pthread_create(&main, NULL, (void *)&start_threads, (void *)&args);
	pthread_join(main, NULL);
	if (args.stop == false && args.param.each_philosopher_must_eat > 0)
		printf("\n\033[32mStop simulation, %u philosophers eated %u times.\
			\033[0m\n\n",
			args.eated_count, args.param.each_philosopher_must_eat);
	if (args.stop)
		printf("\n\033[31mStop simulation, philosopher died.\033[0m\n\n");
	free(args.threads);
	free(args.philo);
	free(args.mxs.forks);
	return (0);
}
