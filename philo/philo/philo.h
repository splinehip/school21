/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:36:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/09/06 21:11:35 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# define UINT unsigned int

typedef struct s_param
{
	UINT			number_of_philosophers;
	UINT			time_to_die;
	UINT			time_to_eat;
	UINT			time_to_sleep;
	UINT			each_philosopher_must_eat;
	struct timeval	start_time;
}	t_param;

typedef struct s_table
{
	pthread_mutex_t	*mx_forks;
	pthread_mutex_t	mx_table;
}	t_table;

typedef struct s_philo
{
	int				id;
	UINT			count_eat;
	UINT			last_eat;
	int				fork_l;
	int				fork_r;
	UINT			*died;
	t_table			*table;
	const t_param	*param;
	pthread_mutex_t	*mx_print;
}	t_philo;

typedef struct s_args
{
	UINT			died;
	t_param			param;
	t_table			table;
	t_philo			*philo;
	pthread_mutex_t	mx_print;
}	t_args;

int		argv_handler(int argc, char **argv, t_param *param);
UINT	time_stamp(const struct timeval *start);
void	start_philo(void *args);

#endif
