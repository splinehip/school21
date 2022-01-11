/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:36:30 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 12:03:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
s1, s2 - pointers to compared strings.

Returned value:
0 - if the compared strings are identical.
-1 - if the compared strings are NULL.
1 - if the compared strings are not identical.

*/
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	if (s1[i] == 0 && s2[i] == 0)
		return (0);
	return (1);
}
