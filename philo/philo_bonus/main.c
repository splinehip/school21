/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:46:27 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/08 13:09:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline	void	free_mem(t_args *args)
{
	free(args->philo);
	free(args->pids);
	free(args->exit_status);
	sem_close(args->sems.table);
	sem_close(args->sems.forks);
	sem_close(args->sems.s_stdout);
	sem_unlink("/table");
	sem_unlink("/forks");
	sem_unlink("/stdout");
}

static inline t_bool	init_args(t_args *args)
{
	args->philo = malloc(args->param.number_of_philosophers * sizeof(t_philo));
	args->pids = malloc(args->param.number_of_philosophers * sizeof(pid_t));
	args->exit_status = malloc(
			args->param.number_of_philosophers * sizeof(int));
	sem_unlink("/table");
	sem_unlink("/forks");
	sem_unlink("/stdout");
	args->sems.table = sem_open("/table", O_CREAT, O_RDWR, (UINT)1);
	args->sems.forks = sem_open("/forks", O_CREAT, O_RDWR,
			args->param.number_of_philosophers);
	args->sems.s_stdout = sem_open("/stdout", O_CREAT, O_RDWR, (UINT)1);
	if (args->philo == NULL || args->pids == NULL || args->exit_status == NULL
		|| args->sems.table == SEM_FAILED || args->sems.forks == SEM_FAILED
		|| args->sems.s_stdout == SEM_FAILED)
	{
		printf("\nMemory allocation for args failed.\n\n");
		free_mem(args);
		return (false);
	}
	args->died = false;
	memset(args->exit_status, -1,
		args->param.number_of_philosophers * sizeof(int));
	return (true);
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
		args->philo[i].param = &args->param;
		args->philo[i].sems = &args->sems;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_bool	th_error;

	if (argv_handler(argc, argv, &args.param))
		return (1);
	if (init_args(&args) == false)
		return (1);
	init_philosophers(&args);
	th_error = start_processes(&args);
	if (th_error == false && args.died == false)
		printf("\n\033[32mStop simulation, %u philosophers eated %u times.\
			\033[0m\n\n", args.param.number_of_philosophers,
			args.param.each_philosopher_must_eat);
	if (th_error == false && args.died)
		printf("\n\033[31mStop simulation, philosopher died.\033[0m\n\n");
	free_mem(&args);
	return (0);
}
