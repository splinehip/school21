/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_validate_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:28:51 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/04 13:48:16 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "actions_handler.h"

static inline int	do_validation_path(
	struct stat *sb, t_action *action, char **path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoinchr(path[i], slash);
		free(path[i]);
		path[i] = ft_strjoin(tmp, action->exec.argv[0]);
		free(tmp);
		if (path[i] && stat(path[i], sb) == success)
		{
			action->exec.path = path[i];
			return (i);
		}
		i++;
	}
	return (-1);
}

static inline int	do_validation_whith_env_path(
	struct stat *sb, t_action *action, char **env)
{
	int		i;
	int		j;
	char	*tmp;
	char	**path;

	i = 0;
	tmp = get_env_value("PATH", env);
	path = ft_split(tmp, colon);
	free(tmp);
	if (path == NULL)
		return (false);
	j = do_validation_path(sb, action, path);
	i = 0;
	while (path[i])
	{
		if (i != j)
			free(path[i]);
		i++;
	}
	free(path);
	if (S_ISREG(sb->st_mode) == false)
		printf(MSG_ERR_CMD_NFOUND, action->exec.argv[0]);
	if (S_ISDIR(sb->st_mode))
		printf(MSG_ERR_CMD_ISDIR, action->exec.argv[0]);
	return (S_ISREG(sb->st_mode));
}

inline int	is_valid_action_path(t_action *action, char **env)
{
	struct stat	sb;

	if (action->exec.argv[0] == NULL)
	{
		printf(MSG_ERR_MEM);
		return (false);
	}
	else if (*action->exec.argv[0] == dot || *action->exec.argv[0] == slash)
	{
		if (stat(action->exec.argv[0], &sb) != success)
		{
			printf(MSG_ERR_CMD_NFOUND, action->exec.argv[0]);
			return (false);
		}
		else if (S_ISDIR(sb.st_mode))
		{
			printf(MSG_ERR_CMD_ISDIR, action->exec.argv[0]);
			return (false);
		}
		return (S_ISREG(sb.st_mode));
	}
	return (do_validation_whith_env_path(&sb, action, env));
}
