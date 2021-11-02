/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:46:27 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/02 17:58:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline	void	free_mem(t_args *args)
{
	free(args->threads);
	free(args->philo);
	free(args->mxs.forks);
}

static inline t_bool	init_args(t_args *args)
{
	UINT	i;

	args->threads = malloc(
			args->param.number_of_philosophers * sizeof(pthread_t));
	args->philo = malloc(args->param.number_of_philosophers * sizeof(t_philo));
	args->mxs.forks = malloc(args->param.number_of_philosophers
			* sizeof(pthread_mutex_t));
	if (args->threads == NULL || args->philo == NULL || args->mxs.forks == NULL)
	{
		free_mem(args);
		printf("\nMemory allocation failed.\n\n");
		return (false);
	}
	args->died = false;
	i = 0;
	while (i < args->param.number_of_philosophers)
		pthread_mutex_init(&args->mxs.forks[i++], NULL);
	pthread_mutex_init(&args->mxs.mx_died, NULL);
	pthread_mutex_init(&args->mxs.mx_stdout, NULL);
	return (true);
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
		args->philo[i].done = 0;
		args->philo[i].died = &args->died;
		args->philo[i].param = &args->param;
		args->philo[i].mxs = &args->mxs;
		pthread_mutex_init(&args->philo[i].mx_done, NULL);
		init_forks(args, i++);
	}
}

int	main(int argc, char **argv)
{
	t_args		args;
	pthread_t	main;
	ULLINT		th_error;

	if (argv_handler(argc, argv, &args.param))
		return (1);
	if (init_args(&args) == false)
		return (1);
	init_philosophers(&args);
	if (pthread_create(&main, NULL, (void *)&start_threads, (void *)&args))
	{
		free_mem(&args);
		printf("\nMain tread creation failed.\n\n");
		return (1);
	}
	pthread_join(main, (void **)&th_error);
	if (th_error == false && args.died == false)
		printf("\n\033[32mStop simulation, %u philosophers eated %u times.\
			\033[0m\n\n", args.param.number_of_philosophers,
			args.param.each_philosopher_must_eat);
	if (th_error == false && args.died)
		printf("\n\033[31mStop simulation, philosopher died.\033[0m\n\n");
	free_mem(&args);
	return (0);
}
