/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:19:32 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/09 13:46:11 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
_p1, _p2 - pointers to freed memory.

Returned values:
The function returns NULL.

Description:
The function takes two pointers to the memory to be freed, calls free for them
and returns NULL.
*/
void	*ft_free(void *_p1, void *_p2)
{
	free(_p1);
	free(_p2);
	return (NULL);
}
