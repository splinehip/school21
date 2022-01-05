/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects_builtin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:11:37 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/05 16:14:42 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "actions_handler.h"

inline int	do_redirects_builtin(t_action action)
{
	int	i;
	int	fd;

	i = 0;
	fd = 1;
	while (i < action.redirects.len)
	{
		i++;
	}
	return (fd);
}
