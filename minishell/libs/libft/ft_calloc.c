/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:19:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:23:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
size_t n - number of memory blocks.
size_t size - block size.

Returned value:
Returns a pointer to the first byte of the selection. Allocated memory
initialized with the null terminator '\\ 0'. If there is not enough memory for
satisfying the request, a null pointer is returned. Always important
check the return value for its NULL equality before using
this pointer.

Description:
The size of the allocated memory is equal to n * size, where size is specified
in bytes. This means that the ft_calloc () function allocates enough memory for
the array from n objects, each size bytes.
*/
void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	res = (void *)malloc(n * size);
	if (res != NULL)
		return (ft_memset(res, '\0', n * size));
	return (NULL);
}
