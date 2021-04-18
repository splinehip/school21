/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <cflorind@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:01:34 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/18 12:45:20 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
