/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:09:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/19 20:17:51 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == (char)c)
			return ((char *)(str + index));
		index++;
	}
	return (NULL);
}
