/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:44:15 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:35:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
dest is a pointer to an array to search for.
c - the code of the required character.
n is the size of the compared part of the array in bytes.

Returned value:
Pointer to the found character, if found in the specified part of the array
required character.
NULL - if the required character is not found.

Description:
The function searches for an entry in the array (memory area) of the character
whose code is given argument c, comparing each byte of the array (memory area)
defined as unsigned char with the code of the desired character. If the required
character is found, then the address of the found character is returned, and the
comparison ends. If, after checks n bytes, the required character was not found,
then the comparison stops and the function returns NULL.
*/
void	*ft_memchr(const void *dest, int c, size_t n)
{
	const unsigned char	*s;

	s = dest;
	while (n--)
	{
		if (*s++ == (unsigned char)c)
			return ((void *)--s);
	}
	return (NULL);
}
