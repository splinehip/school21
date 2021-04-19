/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:53:48 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/19 21:01:10 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	str_len;

	str_len = (int)ft_strlen(str);
	while (str_len >= 0)
	{
		if (str[str_len] == (char)c)
			return ((char *)(str + str_len));
		str_len--;
	}
	return (NULL);
}
