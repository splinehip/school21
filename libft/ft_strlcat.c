/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:32:44 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/19 20:47:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t max)
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

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d_size;
	size_t	s_size;

	d_size = ft_strnlen(dest, n);
	s_size = ft_strlen(src);
	if (d_size == n)
		return (s_size + n);
	if (s_size < n - d_size)
	{
		ft_memcpy(dest + d_size, src, s_size + 1);
	}
	else
	{
		ft_memcpy(dest + d_size, src, n - 1);
		dest[d_size + n] = '\0';
	}
	return (d_size + s_size);
}
