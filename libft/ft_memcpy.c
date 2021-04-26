/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:49:39 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:37:13 by cflorind         ###   ########.fr       */
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
The memcpy function copies n bytes from the array (memory area) that it points
to the src argument to the array (memory area) pointed to by dest.
If the arrays overlap, the result of the copy will be undefined.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
