/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:36:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/07 18:33:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <errno.h>

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
# define S_DONE_NAME_PFX		"/philo_"

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

typedef struct s_sems
{
	sem_t	*table;
	sem_t	*forks;
	sem_t	*s_stdout;
}	t_sems;

typedef struct s_philo
{
	UINT			id;
	UINT			count_eat;
	ULINT			last_eat;
	ULINT			time_stamp;
	t_param			*param;
	t_sems			*sems;
}	t_philo;

typedef struct s_args
{
	t_bool	died;
	t_param	param;
	t_sems	sems;
	t_philo	*philo;
	pid_t	*pids;
	int		*exit_status;
}	t_args;

int		argv_handler(int argc, char **argv, t_param *param);
t_bool	start_processes(t_args *args);
void	start_philo(t_args *args, t_philo *philo);
UINT	uitoa(register UINT n, register UINT i, char *res);
t_bool	write_msg(ULINT time, t_philo *philo, char *msg, int msg_size);
int		exit_status(t_args *args, t_philo *philo);

#endif
