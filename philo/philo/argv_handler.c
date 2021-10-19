/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:50:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/10/19 18:25:49 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static inline int	check_values(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (ft_atol(argv[i]) <= 0)
		{
			printf("Invalid some arguments value: negative or zero...\n");
			return (1);
		}
		j = 0;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				printf("Error: Only numeric arguments acceptable.\n");
				return (1);
			}
			j++;
		}
	}
	return (0);
}

static inline void	set_param(char **argv, t_param *param)
{
	int	i;

	i = 0;
	while (argv[++i] != NULL)
	{
		if (i == 1)
			param->number_of_philosophers = ft_atol(argv[i]);
		else if (i == 2)
			param->time_to_die = ft_atol(argv[i]);
		else if (i == 3)
			param->time_to_eat = ft_atol(argv[i]) * 1000;
		else if (i == 4)
			param->time_to_sleep = ft_atol(argv[i]) * 1000;
		else if (i == 5)
			param->each_philosopher_must_eat = ft_atol(argv[i]);
	}
	if (i == 5)
		param->each_philosopher_must_eat = 0;
}

int	argv_handler(int argc, char **argv, t_param *param)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments. Must be 4 or 5 but entered: %i\n",
			argc - 1);
		return (1);
	}
	if (check_values(argv))
		return (1);
	set_param(argv, param);
	if (param->number_of_philosophers == 1)
	{
		usleep(param->time_to_die * 1000);
		printf("%u ms 1 is died\n", param->time_to_die);
		return (1);
	}
	return (0);
}
