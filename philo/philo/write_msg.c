/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:25:34 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/01 19:23:54 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline UINT	uitoa(register UINT n, register UINT i, char *res)
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

static inline UINT	time_id_to_a(register UINT time, register UINT id,
	char *res)
{
	register UINT	i;

	i = 0;
	i = uitoa(time, i, res);
	res[i++] = ' ';
	i = uitoa(id, i, res);
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
		i = time_id_to_a(time, philo->id, &res_msg[0]);
		j = 0;
		while (j <= msg_size)
			res_msg[i++] = msg[j++];
		pthread_mutex_lock(&philo->mxs->mx_stdout);
		(void)(write(0, res_msg, --i) + 1);
		pthread_mutex_unlock(&philo->mxs->mx_stdout);
		return (true);
	}
	return (false);
}
