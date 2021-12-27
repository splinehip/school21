/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/27 12:16:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"
#include "actions_handler.h"

static inline void	set_action_type(t_actions *action)
{
	char	*name;

	name = action->args.argv[0];
	if (ft_strncmp("echo", name, ft_strlen("echo")) == 0)
		action->type = echo;
	else if (ft_strncmp("cd", name, ft_strlen("cd")) == 0)
		action->type = cd;
	else if (ft_strncmp("pwd", name, ft_strlen("pwd")) == 0)
		action->type = pwd;
	else if (ft_strncmp("export", name, ft_strlen("export")) == 0)
		action->type = export;
	else if (ft_strncmp("unset", name, ft_strlen("unset")) == 0)
		action->type = unset;
	else if (ft_strncmp("env", name, ft_strlen("env")) == 0)
		action->type = env;
	else if (ft_strncmp("exit", name, ft_strlen("exit")) == 0)
		action->type = exit_built;
	else
		action->type = execute;
}

static inline void	do_build_simple(t_actions *actions, char *parsed_str)
{
	char	**splited_str;

	splited_str = ft_split(parsed_str, space);
	if (splited_str == NULL)
		return ;
	if (actions == NULL)
		return ;
	extract_redirects(actions, splited_str);
	actions->args.argv = splited_str;
	set_action_type(actions);
}

static inline void	do_build_pipes(t_actions **actions, char *parsed_str)
{
	int		i;
	char	**splited_str;

	splited_str = ft_split(parsed_str, pipes);
	if (splited_str == NULL)
		return ;
	i = 0;
	while (splited_str[i])
		i++;
	*actions = ft_calloc(i + 1, sizeof(t_actions));
	if (*actions == NULL)
		return ;
	(*actions)[i].end = true;
	i = 0;
	while (splited_str[i])
	{
		(*actions)[i].args.argv = NULL;
		if (i > 0 && splited_str[i + 1])
			add_redirects(*actions + i, input, NULL);
		do_build_simple(*actions + i, splited_str[i]);
		if (splited_str[i + 1] != NULL)
			add_redirects(*actions + i, output, NULL);
		i++;
	}
}

t_actions	*do_actions_build(char *cmd, char **env)
{
	char		*parsed_str;
	t_actions	*actions;

	actions = NULL;
	if (ft_strchr(cmd, asterisk))
		parsed_str = parse_cmd(cmd, env, asterisk);
	else
		parsed_str = parse_cmd(cmd, env, false);
	if (parsed_str == NULL)
		return (actions);
	if (ft_strchr(parsed_str, pipes) == NULL)
	{
		actions = ft_calloc(2, sizeof(t_actions));
		if (actions == NULL)
			return (actions);
		actions->args.redirect = NULL;
		actions[1].end = true;
		do_build_simple(actions, parsed_str);
	}
	else
		do_build_pipes(&actions, parsed_str);
	free(parsed_str);
	return (actions);
}
