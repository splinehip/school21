/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:37:13 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/06 15:22:47 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "error_msgs.h"
#include "minishell.h"

int	do_pwd(t_action action)
{
	int		fd;
	char	*wd;

	fd = do_redirects_builtin(action);
	wd = getcwd(NULL, 0);
	if (!wd)
	{
		print_err(MSG_ERR_PWD, NULL, 0);
		if (fd > 2)
			close(fd);
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
