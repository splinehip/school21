/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:49:01 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/05 20:29:16 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "error_msgs.h"

int	do_echo(t_action action)
{
	int		fd;
	int		i;
	int		nl;

	i = 1;
	fd = do_redirects_builtin(action);
	if (fd > 0)
	{
		nl = ft_strncmp(action.exec.argv[i], "-n", 3);
		if (!nl && action.exec.argv[i])
			i++;
		while (action.exec.argv[i])
		{
			write(fd, action.exec.argv[i], ft_strlen(action.exec.argv[i]));
			if (action.exec.argv[++i])
				write(fd, " ", 1);
		}
		if (nl || i == 1)
			write(fd, "\n", 1);
	}
	if (fd > 2)
		close(fd);
	return (0);
}
