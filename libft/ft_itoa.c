/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:46:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 20:50:20 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	setstr(char *res, unsigned long long dev,
					unsigned long long n_ull, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		res[i++] = '-';
	if (n_ull < 10)
	{
		res[i] = n_ull % dev + 48;
	}
	else
	{
		while (dev != 1)
		{
			dev /= 10;
			res[i++] = n_ull / dev + 48;
			n_ull = n_ull % dev;
		}
	}
}

/*
Аргументы:
n - целое число со знаком которое необходимо перобразовать в строку.

Возвращаемые значения:
Функция возвращает указатель на строку содержащую строковое представление числа.
Если не удалось преобразовать число в строку возвращается NULL.

Описание:
Функция переводит целое число со знаком размера int в строкове представление и
возвращает указатель на строку. Если преобразование не удалось возвращается
NULL.
Если переданное n выходит за диапазон int (-2147483648, +2147483647), то
поведение будет не определеным.
*/
char	*ft_itoa(int n)
{
	int					i;
	unsigned long long	n_ull;
	unsigned long long	dev;
	char				*res;

	i = 0;
	dev = 10;
	n_ull = n;
	if (n < 0)
	{
		i++;
		n_ull *= -1;
	}
	while (++i && n_ull % dev != n_ull)
		dev *= 10;
	res = (char *)ft_calloc(++i, sizeof(char));
	if (res == NULL)
		return (NULL);
	setstr(res, dev, n_ull, n);
	return (res);
}
