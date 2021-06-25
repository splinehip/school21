/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:38:25 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:37:37 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
dest is a pointer to the array into which the data will be copied.
src - pointer to the array of the source of the copied data.
n is the number of bytes to copy.

Return value:
The function returns a pointer to the array into which the data was copied.

Description:
The memmove function copies n bytes from the array (memory area) to which
points to the src argument, into the array (memory area) pointed to by the
argument dest. In this case, arrays (memory areas) can intersect.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		*s_copy;

	d = dest;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		s = (unsigned char *)ft_calloc(n, sizeof(unsigned char));
		if (s != NULL)
		{
			s_copy = ft_memcpy((unsigned char *)s, src, n);
			while (n--)
				*d++ = *s++;
			free(s_copy);
		}
	}
	else
	{
		s = src;
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
