/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:04:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 20:30:53 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
s1 is a pointer to the first line.
s2 is a pointer to the second line.

Returned values:
Returns a pointer to a new, concatenated string, NULL if failed
perform string concatenation.

Description:
The function performs the concatenation of two strings (concatenation) and
returns a pointer to the final row. Returns NULL if string concatenation failed.
*/
char	*ft_strjoin(const char *s1, char const *s2)
{
	char		*res;
	size_t		len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	if (*s1 == '\0' && *s2 == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)ft_calloc(len, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (ft_strlcpy(res, s1, len) && ft_strlcpy(res + ft_strlen(s1), s2, len))
		return (res);
	free(res);
	return (NULL);
}
