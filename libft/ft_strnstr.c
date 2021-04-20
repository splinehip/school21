/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:50:22 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/20 10:22:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DSECRIPTION
The strnstr() function locates the first occurrence of the null-termi-
nated string SUBSTR in the string STR, where not more than len characters
are searched. Characters that appear after a `\0' character are not
searched. Since the strnstr() function is a FreeBSD specific API, it
should only be used when portability is not a concern.

RETURN VALUES
     If	SUBSTR is an empty string, STR is returned; if SUBSTR occurs nowhere
     in	STR, NULL is returned; otherwise a pointer to the first	character of
     the first occurrence of SUBSTR is returned.
*/
static int	ft_check_substr(const char *s, const char *ss)
{
	const char	*s_tmp;

	s_tmp = s;
	while (*ss != '\0')
	{
		if (*s_tmp == '\0')
			return (0);
		if (*s_tmp++ != *ss++)
		{
			return (0);
		}
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	const char	*res;
	const char	*s;
	const char	*ss;

	s = str;
	ss = substr;
	if (!ft_strlen(substr))
		return ((char *)str);
	while (*s != '\0' && n--)
	{
		if (*s++ == *ss)
		{
			res = s - 1;
			if (ft_check_substr(s, ++ss))
				return ((char *)res);
			ss = substr;
		}
	}
	return (NULL);
}
