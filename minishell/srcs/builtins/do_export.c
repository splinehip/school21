/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:57:04 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/11 18:59:54 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "bool.h"
#include "error_msgs.h"
#include "minishell.h"

void	do_update_env(char *str, char ***env)
{
	char	*tmp;
	char	*name;
	char	*value;

	if (str == NULL || env == NULL)
		return ;
	tmp = ft_strchr(str, eq);
	if (tmp == NULL)
		set_env(str, "", env);
	else
	{
		name = ft_substr(str, 0, tmp - str);
		value = ft_substr(tmp + 1, 0, ft_strlen(str) - (tmp - str));
		set_env(name, value, env);
		free(name);
		free(value);
	}
}

int	do_export(t_action action, char ***env)
{
	int		fd;
	int		i;

	i = 1;
	fd = do_redirects_builtin(action);
	if (!action.exec.argv[i] && fd > 0)
	{
		i = 0;
		ft_sort_strs(env);
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
			do_update_env(action.exec.argv[i++], env);
	if (fd > 2)
		close(fd);
	return (0);
}
