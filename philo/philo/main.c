/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:46:27 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/31 14:43:55 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argv_handler(argc, argv, &args))
		return (1);
	printf("%i\n%i\n%i\n%i\n%i\n",
		args.number_of_philosophers,
		args.time_to_die,
		args.time_to_eat,
		args.time_to_sleep,
		args.time_each_philosopher_must_eat);
	return (0);
}
