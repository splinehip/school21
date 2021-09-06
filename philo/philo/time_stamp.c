/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:31:19 by cflorind          #+#    #+#             */
/*   Updated: 2021/09/06 14:31:43 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	time_stamp(const struct timeval *start)
{
	struct timeval	stamp;

	gettimeofday(&stamp, NULL);
	return ((stamp.tv_sec - start->tv_sec) * 1000
		+ (stamp.tv_usec - start->tv_usec) / 1000);
}
