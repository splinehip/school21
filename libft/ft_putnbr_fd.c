/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:39:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 01:00:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Аргументы:
n - число для записи, из диапазона int.
fd - номер дескриптора файла для записи.

Описание:
Функция записывает преданный int n в фаил с дескриптором fd.
*/
void	ft_putnbr_fd(int n, int fd)
{
	int					i;
	unsigned long long	ulln;
	unsigned long long	dev;
	char				res[12];

	i = 0;
	dev = 10;
	ulln = n;
	if (n < 0)
	{
		res[i++] = '-';
		ulln *= -1;
	}
	while (ulln % dev != ulln)
		dev *= 10;
	while (dev != 1)
	{
		dev /= 10;
		res[i++] = ulln / dev + 48;
		ulln = ulln % dev;
	}
	write(fd, &res, i);
}
