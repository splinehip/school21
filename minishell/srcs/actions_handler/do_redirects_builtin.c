/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirects_builtin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:11:37 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/05 17:11:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "actions_handler.h"

inline int	do_redirects_builtin(t_action action)
{
	int	i;
	int	fd;

	i = 0;
	fd = 1;
	while (i < action.redirects.len)
	{
		if (action.redirects.item[i].type == output
			|| action.redirects.item[i].type == output_append)
		{
			if (fd > 2 && fd != action.pipe_out)
				close(fd);
			if (action.redirects.item[i].target == NULL)
				fd = action.pipe_out;
			else
				fd = get_redirects_fd(action.redirects.item[i]);
		}
		i++;
	}
	return (fd);
}
