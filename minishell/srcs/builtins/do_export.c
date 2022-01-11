/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:57:04 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/11 20:50:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "bool.h"
#include "error_msgs.h"
#include "minishell.h"

static inline void	do_print(char **env)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (env[i])
	{
		name = get_env_name(env[i++]);
		value = get_env_value(name, env);
		printf("%s %s=\"%s\"\n", EXPORT_PREPEND, name, value);
		free(name);
		free(value);
	}
}

inline void	do_print_env(int fd, char **env)
{
	int		saved_stdout;

	if (env == NULL)
		return ;
	ft_sort_strs(&env);
	if (fd > 0)
	{
		saved_stdout = dup(STDOUT_FILENO);
		dup2(fd, STDOUT_FILENO);
		do_print(env);
		dup2(saved_stdout, STDOUT_FILENO);
	}
	else
		do_print(env);
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
	if (action.exec.argv[i] == NULL)
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
