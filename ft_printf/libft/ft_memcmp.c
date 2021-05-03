/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:49:28 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:36:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:

left, rigth - pointers to compared arrays.
n is the size of the compared part of the array in bytes.

Returned value:
0 - if the compared parts of the arrays are identical.

A positive number if a different byte and a byte are encountered when comparing
arrays from the array pointed to by the left argument is more byte from the
array, by which specifies the rigth argument.

A negative number if a different byte and a byte are encountered when comparing
arrays from the array pointed to by left is less than a byte from the array, by
which specifies the rigth argument.

Description:
The function compares the two arrays (memory areas) pointed to by byte
arguments left and rigth. Each byte of the array is defined as an unsigned char
type. The comparison continues until n bytes have been checked or until
differing bytes.
*/
int	ft_memcmp(const void *left, const void *rigth, size_t n)
{
	unsigned char	*l;
	unsigned char	*r;

	l = (unsigned char *)left;
	r = (unsigned char *)rigth;
	if (!n)
		return (0);
	while (*l == *r && n--)
	{
		if (n)
		{
			l++;
			r++;
		}
	}
	return (*l - *r);
}
