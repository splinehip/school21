/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_build_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:54:00 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/13 14:30:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "actions_handler.h"

inline void	set_action_type(t_action *action)
{
	char	*name;

	if (action->exec.argv == NULL || !action->exec.argv[0])
		return ;
	name = action->exec.argv[0];
	if (ft_strcmp("echo", name) == success)
		action->type = echo;
	else if (ft_strcmp("cd", name) == success)
		action->type = cd;
	else if (ft_strcmp("pwd", name) == success)
		action->type = pwd;
	else if (ft_strcmp("export", name) == success)
		action->type = export;
	else if (ft_strcmp("unset", name) == success)
		action->type = unset;
	else if (ft_strcmp("env_built", name) == success)
		action->type = env_built;
	else if (ft_strcmp("exit", name) == success)
		action->type = exit_built;
	else
		action->type = execute;
}

inline void	set_action_argv(t_action *action, int start, int len, char **cmds)
{
	int	i;

	action->exec.argv = ft_calloc(len + 1, sizeof(char *));
	if (action->exec.argv == NULL)
		return ;
	i = 0;
	while (i < len)
	{
		action->exec.argv[i] = ft_strdup(cmds[start + i]);
		i++;
	}
}
