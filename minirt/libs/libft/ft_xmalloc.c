/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:01:01 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/27 11:16:10 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:

size_t size - number of memory blocks * block size.

Returned value:

Returns a pointer to the first byte of the selection. If there is not enough
memory for satisfying the request, a function will print "Error: out of memory\n"
in stderror and calling syscall exit(unsaccess).

Description:
The size of the allocated memory is equal to size, where size is specified
in bytes.
*/
void	*ft_xmalloc(size_t size)
{
	void	*res;

	res = (void *)malloc(size);
	if (res != NULL)
		return (res);
	else
	{
		(void)(write(2, "Error: out of memory\n", 21) + 1);
		exit(1);
	}
}
