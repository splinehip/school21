/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:39:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 22:32:42 by cflorind         ###   ########.fr       */
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
	unsigned long long	n_ull;
	unsigned long long	dev;
	char				res[12];

	i = 0;
	dev = 10;
	n_ull = n;
	if (n < 0)
	{
		res[i++] = '-';
		n_ull *= -1;
	}
	while (n_ull % dev != n_ull)
		dev *= 10;
	while (dev != 1)
	{
		dev /= 10;
		res[i++] = n_ull / dev + 48;
		n_ull = n_ull % dev;
	}
	write(fd, &res, i);
}
