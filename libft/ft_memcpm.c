/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:49:28 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/19 14:27:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcpm(const void *left, const void *rigth, size_t n)
{
	unsigned char	*l;
	unsigned char	*r;

	l = (unsigned char *)left;
	r = (unsigned char *)rigth;
	if (!n)
		return (0);
	while (n-- && *l != *r)
	{
		l++;
		r++;
	}
	return (*l - *r);
}
