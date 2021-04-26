/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:50:22 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:48:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:

str is a pointer to the string being searched.
substr is a pointer to the search string.
n is the number of characters to search.

Returned value:
NULL - if string substr is not included in string str. Pointer to first
occurrence substr strings to str string.

Description:
The strnstr function searches for the first occurrence of a string (excluding
the end character string) pointed to by substr to the string pointed to
argument str. The search in str is not performed in n characters. If the string
substr has zero length, the function will return a pointer to the beginning of
the string str.
*/
char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	const char	*res;
	const char	*s;
	const char	*ss;

	if (str == NULL || substr == NULL || n < ft_strlen(substr))
		return (NULL);
	s = str;
	ss = substr;
	if (!ft_strlen(substr))
		return ((char *)str);
	while (*s && ft_strlen(substr) <= n--)
	{
		if (*s++ == *ss)
		{
			ss++;
			res = s - 1;
			if (!ft_strncmp(s, ss, ft_strlen(ss)))
				return ((char *)res);
			ss = substr;
		}
	}
	return (NULL);
}
