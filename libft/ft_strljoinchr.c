/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoinchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:17:24 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/17 18:23:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
res - a pointer to the string to which the character should be added.
c - character code to add.

Returned values:
The function returns a pointer to the concatenated string. If failed to complete
union returns NULL.

Description:
The function performs the concatenation of a string and character into a new
string. Symbol appended to the begining of the string. On success, a pointer to
a new line is returned. If the join fails, NULL is returned.
*/
char	*ft_strljoinchr(char *res, char c)
{
	char	*tmp;

	if (res != NULL && c == 0)
		return (ft_strdup(res));
	if (res == NULL)
		return (ft_memcpy((char *)ft_calloc(2, sizeof(char)), &c, 1));
	tmp = (char *)ft_calloc(ft_strlen(res) + 2, sizeof(char));
	if (tmp != NULL)
	{
		tmp[0] = c;
		ft_memcpy(tmp + 1, res, ft_strlen(res));
	}
	if (tmp != NULL && ft_strlen(tmp) == ft_strlen(res) + 1)
		return (tmp);
	if (tmp != NULL)
		free(tmp);
	return (NULL);
}
