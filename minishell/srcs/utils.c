/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:49:46 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/06 12:23:18 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

static inline void	error_and_exit(void)
{
	print_err("Error: memory allocation failure\n", NULL, 0);
	exit(1);
}

void	*xmalloc(size_t n, size_t size)
{
	void	*res;

	res = ft_calloc(n, size);
	if (res == NULL)
		error_and_exit();
	return (res);
}
