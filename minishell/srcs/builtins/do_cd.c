/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:08:47 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/10 16:05:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "libft.h"
#include "builtins.h"
#include "error_msgs.h"
#include "minishell.h"

static void	update_pwd_values(char **env, char *old_dir, char *new_dir)
{
	char	*new_val;
	char	*old_val;

	new_val = get_env_value("PWD", env);
	if (new_val)
		set_env("PWD", new_dir, env);
	old_val = get_env_value("OLDPWD", env);
	if (old_val)
		set_env("OLDPWD", old_dir, env);
	free(new_val);
	free(old_val);
}

static int	change_dir(char **env, char *old_dir, char *path, int cd_res)
{
	char	*new_dir;

	if (cd_res == -1)
	{
		print_err(MSG_ERR_CD, path, 0);
		print_err("%s\n", strerror(errno), 0);
		return (1);
	}
	else
	{
		new_dir = getcwd(NULL, 0);
		if (ft_strncmp(new_dir, old_dir, ft_strlen(new_dir) + 1) != 0)
			update_pwd_values(env, old_dir, new_dir);
		free(new_dir);
	}
	return (0);
}

int	run_cd(t_action action, char **env)
{
	char	*path;
	char	*old_dir;
	int		res;

	path = NULL;
	if (!(action.exec.argv[1]))
		path = get_env_value("HOME", env);
	else
		path = ft_strdup(action.exec.argv[1]);
	if (!path)
	{
		print_err(MSG_ERR_CD, NULL, 0);
		return (1);
	}
	old_dir = getcwd(NULL, 0);
	res = change_dir(env, old_dir, path, chdir(path));
	free(path);
	free(old_dir);
	return (res);
}

int	do_cd(t_action action, char **env)
{
	int		fd;

	fd = do_redirects_builtin(action);
	if (fd > 2)
		close(fd);
	if (action.exec.argv[1] && action.exec.argv[2])
	{
		print_err(MSG_ERR_CD_ARGS, NULL, 0);
		return (1);
	}
	if (action.redirect_out.type >= 0)
		return (0);
	return (run_cd(action, env));
}
