/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:46:27 by cflorind          #+#    #+#             */
/*   Updated: 2021/09/06 21:13:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	init_args(t_args *args, pthread_t **threads)
{
	UINT	i;

	*threads = malloc(args->param.number_of_philosophers * sizeof(pthread_t));
	args->philo = malloc(args->param.number_of_philosophers * sizeof(t_philo));
	args->table.mx_forks = malloc(args->param.number_of_philosophers
			* sizeof(pthread_mutex_t));
	args->died = 0;
	pthread_mutex_init(&args->table.mx_table, NULL);
	pthread_mutex_init(&args->mx_print, NULL);
	i = 0;
	while (i < args->param.number_of_philosophers)
		pthread_mutex_init(&args->table.mx_forks[i++], NULL);
}

static inline void	init_forks(t_args *args, UINT i)
{
	if (args->param.number_of_philosophers == 1)
	{
		args->philo[i].fork_l = 0;
		args->philo[i].fork_r = 0;
	}
	else if (i == 0)
	{
		if (args->param.number_of_philosophers == 2)
			args->philo[i].fork_l = 0;
		else
			args->philo[i].fork_l = args->param.number_of_philosophers - 1;
		args->philo[i].fork_r = 1;
	}
	else if (i == args->param.number_of_philosophers - 1)
	{
		args->philo[i].fork_l = i;
		args->philo[i].fork_r = 0;
	}
	else
	{
		args->philo[i].fork_l = i - 1;
		args->philo[i].fork_r = i + 1;
	}
}

static inline void	init_philo(t_args *args, UINT i)
{
	args->philo[i].id = i + 1;
	args->philo[i].last_eat = 0;
	args->philo[i].count_eat = 0;
	args->philo[i].died = &args->died;
	args->philo[i].param = &args->param;
	args->philo[i].table = &args->table;
	args->philo[i].mx_print = &args->mx_print;
	init_forks(args, i);
}

int	main(int argc, char **argv)
{
	UINT		i;
	t_args		args;
	pthread_t	*threads;

	gettimeofday(&args.param.start_time, NULL);
	if (argv_handler(argc, argv, &args.param))
		return (1);
	init_args(&args, &threads);
	i = 0;
	while (i < args.param.number_of_philosophers)
	{
		init_philo(&args, i);
		pthread_create(&threads[i], NULL, (void *)&start_philo,
			(void *)&args.philo[i]);
		usleep(i % 2);
		i++;
	}
	i = 0;
	while (i < args.param.number_of_philosophers)
		pthread_join(threads[i++], NULL);
	printf("!!!!!!!!!!!!!!\n");
	free(threads);
	free(args.philo);
	free(args.table.mx_forks);
	return (0);
}
