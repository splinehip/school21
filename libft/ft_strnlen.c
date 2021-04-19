/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:15:33 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/19 19:15:57 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t max)
{
	size_t	str_len;

	str_len = 0;
	while (str_len < max)
	{
		if (str[str_len] == '\0')
			return (str_len);
		str_len++;
	}
	return (max);
}
