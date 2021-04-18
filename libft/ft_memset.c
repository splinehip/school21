/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:01:34 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/18 15:51:33 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t l)
{
	unsigned char	*buf_tmp;

	buf_tmp = (unsigned char *)buf;
	while (l--)
	{
		*buf_tmp++ = (unsigned char)c;
	}
	return (buf);
}
