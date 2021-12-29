/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_validate_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:28:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/29 13:47:47 by cflorind         ###   ########.fr       */
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

static inline int	do_validation_whith_path(
	struct stat *sb, t_actions *action, char **env)
{
	int		i;
	int		j;
	char	*tmp;
	char	**path;

	i = 0;
	j = -1;
	tmp = get_env_value("PATH", env);
	path = ft_split(tmp, colon);
	if (path == NULL)
		return (false);
	while (path[i])
	{
		tmp = ft_strjoinchr(path[i], slash);
		free(path[i]);
		path[i] = ft_strjoin(tmp, action->args.argv[0]);
		free(tmp);
		if (path[i] && stat(path[i], sb) == sucsses)
		{
			action->args.path = path[i];
			j = i;
			break ;
		}
		i++;
	}
	i = 0;
	while (path[i])
	{
		if (j < 0 || (j > 0 && i != j))
			free(path[i]);
		i++;
	}
	free(path);
	if (S_ISREG(sb->st_mode) == false)
		printf(MSG_ERR_CMD_NFOUND, action->args.argv[0]);
	if (S_ISDIR(sb->st_mode))
		printf(MSG_ERR_CMD_ISDIR, action->args.argv[0]);
	return (S_ISREG(sb->st_mode));
}

inline int	is_valid_action(t_actions *action, char **env)
{
	struct stat	sb;

	if (action->args.argv[0] == NULL)
	{
		printf("minishel: %s\n", MSG_ERR_MEM);
		return (false);
	}
	else if (*action->args.argv[0] == dot || *action->args.argv[0] == slash)
	{
		if (stat(action->args.argv[0], &sb) == unsucsses)
		{
			printf(MSG_ERR_CMD_NFOUND, action->args.argv[0]);
			return (false);
		}
		else if (S_ISDIR(sb.st_mode))
		{
			printf(MSG_ERR_CMD_ISDIR, action->args.argv[0]);
			return (false);
		}
		return (S_ISREG(sb.st_mode));
	}
	return (do_validation_whith_path(&sb, action, env));
}
