/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:57:04 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/11 10:36:55 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "minishell.h"

int	do_export(t_action action, char ***env)
{
	int		fd;
	int		i;

	i = 1;
	fd = do_redirects_builtin(action);
	if (!action.exec.argv[i] && fd > 0)
	{
		i = 0;
		while ((*env)[i])
		{
			write(fd, EXPORT_PREPEND, ft_strlen(EXPORT_PREPEND));
			write(fd, (*env)[i], ft_strlen((*env)[i]));
			write(fd, "\n", 1);
			i++;
		}
	}
	else
		while (action.exec.argv[i])
			set_env(action.exec.argv[i++], "NULL", env);
	if (fd > 2)
		close(fd);
	return (0);
}
