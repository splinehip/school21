/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/10 21:08:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"
#include "actions_handler.h"

static inline void	set_action_type(t_action *action)
{
	char	*name;

	if (action->exec.argv == NULL || !action->exec.argv[0])
		return ;
	name = action->exec.argv[0];
	if (ft_strncmp("echo", name, ft_strlen("echo") + 1) == 0)
		action->type = echo;
	else if (ft_strncmp("cd", name, ft_strlen("cd") + 1) == 0)
		action->type = cd;
	else if (ft_strncmp("pwd", name, ft_strlen("pwd") + 1) == 0)
		action->type = pwd;
	else if (ft_strncmp("export", name, ft_strlen("export") + 1) == 0)
		action->type = export;
	else if (ft_strncmp("unset", name, ft_strlen("unset") + 1) == 0)
		action->type = unset;
	else if (ft_strncmp("env", name, ft_strlen("env") + 1) == 0)
		action->type = env;
	else if (ft_strncmp("exit", name, ft_strlen("exit") + 1) == 0)
		action->type = exit_built;
	else
		action->type = execute;
}

static inline void	do_init_actions_items(t_actions *actions, int count)
{
	int	i;

	if (count == 0)
		return ;
	actions->item = ft_calloc(count, sizeof(t_action));
	if (actions->item == NULL)
		return ;
	actions->len = count;
	i = 0;
	while (i < actions->len)
	{
		actions->item[i].pid = 0;
		actions->item[i].pipe_in = 0;
		actions->item[i].pipe_out = 0;
		actions->item[i].exec.path = NULL;
		actions->item[i].exec.argv = NULL;
		actions->item[i].redirect_in.type = -1;
		actions->item[i].redirect_in.target = NULL;
		actions->item[i].redirect_out.type = -1;
		actions->item[i].redirect_out.target = NULL;
		actions->item[i].pipe_read_input[in] = 0;
		actions->item[i].pipe_read_input[out] = 0;
		i++;
	}
}

static inline void	do_init_pipes(t_actions *actions, char ***splited_str)
{
	int	i;

	if (actions->len)
	{
		actions->pipes.item = ft_calloc(actions->len - 1, sizeof(t_pipe));
		if (actions->pipes.item)
			actions->pipes.len = actions->len - 1;
	}
	else
	{
		i = 0;
		while ((*splited_str)[i])
			free((*splited_str)[i++]);
		free(*splited_str);
		free(actions->item);
		*splited_str = NULL;
		actions->item = NULL;
		actions->len = 0;
	}
}

static inline void	do_build_pipes(
	t_actions *actions, char *parsed_str, char **env)
{
	int		i;
	char	**splited_str;
	char	**argv;

	splited_str = ft_split(parsed_str, pipes);
	i = 0;
	while (splited_str && splited_str[i])
		i++;
	do_init_actions_items(actions, i);
	do_init_pipes(actions, &splited_str);
	i = 0;
	while (i < actions->len)
	{
		if (i != 0)
			actions->item[i].redirect_in.type = input;
		if (i + 1 < actions->len)
			actions->item[i].redirect_out.type = output;
		argv = ft_split(splited_str[i], space);
		extract_redirects(&actions->item[i], argv, env);
		actions->item[i].exec.argv = argv;
		set_action_type(&actions->item[i]);
		free(splited_str[i]);
		i++;
	}
	free(splited_str);
}

t_actions	*do_actions_build(t_actions *actions, char *cmd, char ***env)
{
	char	*parsed_str;
	char	**splited_str;

	if (ft_strchr(cmd, asterisk))
		parsed_str = parse_cmd(cmd, *env, asterisk);
	else
		parsed_str = parse_cmd(cmd, *env, false);
	if (parsed_str == NULL)
		return (actions);
	if (ft_strchr(parsed_str, pipes) == NULL)
	{
		do_init_actions_items(actions, 1);
		if (actions->len)
		{
			splited_str = ft_split(parsed_str, space);
			extract_redirects(actions->item, splited_str, *env);
			actions->item->exec.argv = splited_str;
			set_action_type(actions->item);
		}
	}
	else
		do_build_pipes(actions, parsed_str, *env);
	free(parsed_str);
	return (actions);
}
