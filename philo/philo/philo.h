/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:36:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/19 14:33:26 by cflorind         ###   ########.fr       */
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

typedef enum e_bool
{
	false,
	true,
}	t_bool;

typedef struct s_param
{
	UINT			number_of_philosophers;
	UINT			time_to_die;
	UINT			time_to_eat;
	UINT			time_to_sleep;
	UINT			each_philosopher_must_eat;
	struct timeval	start_time;
}	t_param;

typedef struct s_mxs
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	stop;
	pthread_mutex_t	eated_count;
}	t_mxs;

typedef struct s_philo
{
	int		id;
	UINT	count_eat;
	UINT	last_eat;
	UINT	current_time;
	int		fork_l;
	int		fork_r;
	t_bool	died;
	UINT	*eated_count;
	t_bool	*stop;
	t_param	*param;
	t_mxs	*mxs;
}	t_philo;

typedef struct s_args
{
	t_param		param;
	t_philo		*philo;
	t_mxs		mxs;
	t_bool		stop;
	UINT		eated_count;
	pthread_t	*threads;
}	t_args;

int		argv_handler(int argc, char **argv, t_param *param);
UINT	time_stamp(const struct timeval *start);
void	start_philo(void *args);
void	start_threads(void *targs);

#endif
