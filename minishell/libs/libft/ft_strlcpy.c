/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:31:35 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:45:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
dest is a pointer to the string to which the data will be copied.
src - pointer to the string source of the copied data.
l is the size of the string dest.

Return value:
The function returns the size of the src string.

Description:
Ft_strlcpy copies at most l - 1 from src to dest buffer
characters and is guaranteed to set a null character at the end of the string.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t l)
{
	size_t		count;

	if (!dest || !src)
		return (0);
	if (l == 0)
		return (ft_strlen(src));
	count = 0;
	while (src[count] != '\0' && count < l - 1)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}
