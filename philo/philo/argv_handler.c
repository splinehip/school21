/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:50:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/31 14:41:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	has_no_numeric(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != NULL)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
	}
	return (0);
}

static inline int	ft_atol(const char *str)
{
	long int	n;
	long int	res;
	const char	*s;

	n = 0;
	res = 0;
	s = str;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			n = 1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	if (n)
		res *= -1;
	return (res);
}

static inline void 	set_args(char **argv, t_args *args)
{
	int	i;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (i == 1)
			args->number_of_philosophers = ft_atol(argv[i]);
		else if (i == 2)
			args->time_to_die = ft_atol(argv[i]);
		else if (i == 3)
			args->time_to_eat = ft_atol(argv[i]);
		else if (i == 4)
			args->time_to_sleep = ft_atol(argv[i]);
		else if (i == 5)
			args->time_each_philosopher_must_eat = ft_atol(argv[i]);
	}
}

int	argv_handler(int argc, char **argv, t_args *args)
{
	if (argc != 6)
	{
		printf("Invalid number of arguments. Must be 5 but entered: %i\n",
			argc - 1);
		return (1);
	}
	if (has_no_numeric(argv))
	{
		printf("Invalid arguments. Only numeric arguments acceptable.\n");
		return (1);
	}
	set_args(argv, args);
	return (0);
}
