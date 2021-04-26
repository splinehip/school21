/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:32:44 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:44:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t max)
{
	size_t	str_len;

	str_len = 0;
	while (str_len < max)
	{
		if (str[str_len] == '\0')
			return (str_len);
		str_len++;
	}
	return (max);
}

/*
Arguments:

dest is a pointer to an array to which the string will be added.
src - pointer to the array from which the string will be copied.
n is the size of the dest array.

Returned value:
The function returns the sum of the lengths of the strings dest and src.

Description:
The function adds to the string pointed to by the argument dest, a string, to
pointed to by src until an end-of-line character is encountered, or until
no n - padded part dest - 1 characters will be added.
It is guaranteed to set the end-of-line character at the end of concatenated
lines. For the function to work correctly, it only needs to pass zero-terminal
strings.
If the lines overlap, the result of the concatenation will be undefined.
*/
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d_size;
	size_t	s_size;

	if (dest == NULL || src == NULL)
		return (0);
	d_size = ft_strnlen(dest, n);
	s_size = ft_strlen(src);
	if (d_size == n)
		return (s_size + n);
	if (s_size < n - d_size)
		ft_memcpy(dest + d_size, src, s_size + 1);
	else
	{
		ft_memcpy(dest + d_size, src, n - d_size);
		dest[n - 1] = '\0';
	}
	return (d_size + s_size);
}
