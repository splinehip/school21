/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:50:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/27 22:38:25 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	inset(const char *set, const char c)
{
	const char	*s;

	s = set;
	while (*s != '\0')
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}

/*
Arguments:
s1 - pointer to the string in which you want to remove characters.
set is a pointer to a string with characters to delete.

Returned values:
Returns a pointer to a new line without characters from set at the beginning
and end strings. If it was not possible to allocate memory - NULL.

Description:
The function removes from the original string, at the beginning and end of the
string, characters from set and returns a pointer to a new, truncated string.
If it was not possible to allocate memory or copy string returns NULL.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	rigth;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	left = 0;
	rigth = ft_strlen(s1);
	while (s1[left] != '\0' && inset(set, s1[left]))
		left++;
	if (s1[left] == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	while (rigth--)
	{
		if (!inset(set, s1[rigth]))
			break ;
	}
	res = (char *)ft_calloc(rigth - left + 2, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (ft_strlcpy(res, s1 + left, (rigth - left) + 2))
		return (res);
	return (NULL);
}
