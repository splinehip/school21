/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:55:52 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/27 11:16:15 by cflorind         ###   ########.fr       */
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
satisfying the request, a function will print "Error: out of memory\n" in
stderror and calling syscall exit(unsaccess).

Description:

The size of the allocated memory is equal to n * size, where size is specified
in bytes. This means that the ft_xcalloc () function allocates enough memory for
the array from n objects, each size bytes.
*/
void	*ft_xcalloc(size_t n, size_t size)
{
	void	*res;

	res = (void *)malloc(n * size);
	if (res != NULL)
		return (ft_memset(res, '\0', n * size));
	else
	{
		(void)(write(2, "Error: out of memory\n", 21) + 1);
		exit(1);
	}
}
