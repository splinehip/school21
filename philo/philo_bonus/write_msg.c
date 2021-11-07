/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:25:34 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/07 17:19:16 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

__always_inline UINT	uitoa(register UINT n, register UINT i, char *res)
{
	register ULLINT	dev;
	register ULLINT	ulln;

	dev = 10;
	ulln = n;
	while (ulln % dev != ulln)
		dev *= 10;
	while (dev != 1)
	{
		dev /= 10;
		res[i++] = ulln / dev + 48;
		ulln = ulln % dev;
	}
	return (i);
}

t_bool	write_msg(register ULINT time, t_philo *philo, char *msg,
	register int msg_size)
{
	register UINT	i;
	register int	j;
	char			res_msg[MAX_MSG_SIZE];

	if (time - philo->last_eat <= philo->param->time_to_die)
	{
		i = uitoa(time, 0, &res_msg[0]);
		res_msg[i++] = '\t';
		i = uitoa(philo->id, i, &res_msg[0]);
		j = 0;
		while (j <= msg_size)
			res_msg[i++] = msg[j++];
		sem_wait(philo->sems->s_stdout);
		(void)(write(1, res_msg, --i) + 1);
		sem_post(philo->sems->s_stdout);
		return (true);
	}
	return (false);
}
