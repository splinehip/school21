/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:38:25 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/19 13:29:34 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		while (n)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
