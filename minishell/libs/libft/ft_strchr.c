/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:09:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:42:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
str is a pointer to the string to be searched.
c - the code of the required character.

Return value:
Pointer to the desired character, if found in str, otherwise NULL.

Description:
The function searches for the first occurrence from the BEGINNING of a string
of a character whose code is specified in argument c, on the line pointed to
by str.
*/
char	*ft_strchr(const char *str, int c)
{
	const char	*s;

	if (str == NULL)
		return (NULL);
	s = str;
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s++)
			break ;
	}
	return (NULL);
}
