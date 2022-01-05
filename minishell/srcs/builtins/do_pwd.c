/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:37:13 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/05 16:16:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "error_msgs.h"

int	do_pwd(t_action action, char **env)
{
	int		fd;
	char	*wd;

	fd = do_redirects_builtin(action);
	wd = get_env_value("PWD", env);
	if (!wd)
	{
		printf(MSG_ERR_PWD);
		return (1);
	}
	if (fd > 0)
	{
		write(fd, wd, ft_strlen(wd));
		write(fd, "\n", 1);
	}
	if (fd > 2)
		close(fd);
	free(wd);
	return (0);
}
