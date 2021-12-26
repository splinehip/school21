/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:49:46 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/26 11:54:30 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

static inline void	error_and_exit(void)
{
	ft_printf("Error: memory allocation failure\n");
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
