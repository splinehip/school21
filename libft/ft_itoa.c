/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:46:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:28:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
n is a signed integer to be converted to a string.

Returned values:
The function returns a pointer to a string containing the string representation
of a number. If the number cannot be converted to a string, NULL is returned.

Description:
The function translates a signed integer of size int into a string
representation and returns a pointer to a string. If the conversion failed, it
returns NULL.
If the passed n is out of range int (-2147483648, +2147483647), then the
behavior will be undefined.
*/
char	*ft_itoa(int n)
{
	int					i;
	unsigned long long	ulln;
	unsigned long long	dev;
	char				res[12];

	ft_memset(res, '\0', 12);
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
	return (ft_strdup(res));
}
