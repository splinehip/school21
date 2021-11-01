/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:36:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/29 13:23:46 by cflorind         ###   ########.fr       */
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
# define ULINT unsigned long int
# define ULLINT unsigned long long int
# define MSG_TAKEN_FORK			"\033[33m has taken a fork\033[0m\n"
# define SIZE_MSG_TAKEN_FORK	27
# define MSG_EATING				"\033[32m is eating\033[0m\n"
# define SIZE_MSG_EATING		20
# define MSG_SLEEPING			"\033[35m is sleeping\033[0m\n"
# define SIZE_MSG_SLEEPING		22
# define MSG_THINKING			"\033[36m is thinking\033[0m\n"
# define SIZE_MSG_THINKING		22
# define MSG_DIED				"\033[31m died\033[0m\n"
# define MAX_MSG_SIZE			100

typedef enum e_bool
{
	false,
	true,
}	t_bool;

typedef struct s_param
{
	UINT	number_of_philosophers;
	UINT	time_to_die;
	UINT	time_to_eat;
	UINT	time_to_sleep;
	UINT	each_philosopher_must_eat;
	ULINT	start_time;
}	t_param;

typedef struct s_mxs
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mx_stdout;
}	t_mxs;

typedef struct s_philo
{
	UINT			id;
	UINT			count_eat;
	ULINT			last_eat;
	ULINT			time_stamp;
	int				fork_1;
	int				fork_2;
	t_bool			done;
	t_param			*param;
	t_mxs			*mxs;
	pthread_mutex_t	mx_done;
}	t_philo;

typedef struct s_args
{
	UINT		id;
	UINT		died;
	t_param		param;
	t_philo		*philo;
	t_mxs		mxs;
	pthread_t	*threads;
}	t_args;

int		argv_handler(int argc, char **argv, t_param *param);
void	start_threads(void *targs);
void	start_philo(void *args);
t_bool	write_msg(ULINT time, t_philo *philo, char *msg, int msg_size);

#endif
