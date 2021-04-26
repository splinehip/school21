/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:37:23 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:42:52 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
str is a pointer to the duplicated string.

Return value:
NULL - if it is not possible to allocate memory for a new line or copy a line
pointed to by the str argument. A pointer to a duplicate string.

Description:
The strdup function duplicates the string pointed to by the str argument.
Memory for a duplicate string is allocated using the malloc function, and at
the end work with a duplicate should be cleaned up with the free function.
*/
char	*ft_strdup(char *str)
{
	size_t	str_len;
	char	*str_dup;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str) + 1;
	str_dup = (char *)ft_calloc(str_len, sizeof(char));
	if (str_dup != NULL)
	{
		ft_strlcpy(str_dup, str, str_len);
		if (!ft_strncmp(str_dup, str, str_len))
			return (str_dup);
	}
	return (NULL);
}
