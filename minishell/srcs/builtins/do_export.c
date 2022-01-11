/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:57:04 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/11 20:00:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "bool.h"
#include "error_msgs.h"
#include "minishell.h"

static inline void	do_print_env(int fd, char **env)
{
	int	i;

	i = 0;
	ft_sort_strs(&env);
	while (env[i])
	{
		write(fd, EXPORT_PREPEND, ft_strlen(EXPORT_PREPEND));
		write(fd, env[i], ft_strlen(env[i]));
		write(fd, "\n", 1);
		i++;
	}
}

static inline int	do_update_env(char *str, char ***env)
{
	char	*tmp;
	char	*name;
	char	*value;

	if (str == NULL || env == NULL)
		return (unsuccess);
	if (ft_isalpha(*str) == false)
	{
		print_err(MSG_ERR_INVAL_ENVNAME, str, false);
		return (unsuccess);
	}
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
	return (success);
}

int	do_export(t_action action, char ***env)
{
	int		i;
	int		fd;
	int		res;

	i = 1;
	fd = do_redirects_builtin(action);
	res = success;
	if (!action.exec.argv[i] && fd > 0)
		do_print_env(fd, *env);
	else
	{
		while (action.exec.argv[i])
		{
			if (res == success)
				res = do_update_env(action.exec.argv[i++], env);
			else
				do_update_env(action.exec.argv[i++], env);
		}
	}
	if (fd > 2)
		close(fd);
	return (res);
}
