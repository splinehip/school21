/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:19:32 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/29 20:22:41 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	res;

	res = 0;
	while (str[res] != '\0')
	{
		res++;
	}
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

void	*ft_memset(void *buf, int c, size_t l)
{
	unsigned char	*buf_tmp;

	if (!buf)
		return (NULL);
	buf_tmp = (unsigned char *)buf;
	while (l--)
	{
		*buf_tmp++ = (unsigned char)c;
	}
	return (buf);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	res = (void *)malloc(n * size);
	if (res != NULL)
		return (ft_memset(res, '\0', n * size));
	return (NULL);
}

void	*_free(void *_p1, void *_p2)
{
	free(_p1);
	if (_p2 != NULL)
		free(_p2);
	return (NULL);
}
