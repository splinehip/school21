/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:24:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:34:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
dest is a pointer to the array into which the data will be copied.
src - pointer to the array of the source of the copied data.
c - the code of the character, upon meeting which the copying is completed.
n is the number of bytes to copy.

Returned value:
The function returns a pointer to the next character in dest after c or NULL if
c was not found in the first n characters of src.

Description:
The function copies data from the array (memory area) that it points to
the src argument, into the array (memory area) pointed to by the dest argument
while no character is found whose code matches the one specified in the argument
c, or until n bytes of data have been copied.
If the arrays overlap, the result of the copy will be undefined.
*/
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (n--)
	{
		*d++ = *s;
		if (*s == (unsigned char)c)
			return (d);
		s++;
	}
	return (NULL);
}
