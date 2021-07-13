/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:55:49 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/18 14:19:13 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
n is a unsigned integer to be converted to a string.

Returned values:
The function returns a pointer to a string containing the string representation
of a number. If the number cannot be converted to a string, NULL is returned.

Description:
The function translates a unsigned integer n of size unsigned int into a string
representation and returns a pointer to a string. If the conversion failed, it
returns NULL.
If the passed n is negative number, then the result equal 4294967296 - n because
is unsigned integer overflow.
*/
char	*ft_uitoa(unsigned int n)
{
	int		i;
	t_ulli	ulln;
	t_ulli	dev;
	char	res[11];

	ft_memset(res, '\0', 11);
	i = 0;
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
	return (ft_strdup(res));
}
