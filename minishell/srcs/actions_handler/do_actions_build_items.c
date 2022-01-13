/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_build_items.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:51:25 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/13 14:48:07 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"
#include "actions_handler.h"

static inline void	do_init_actions_items(t_actions *actions, int count)
{
	int	i;

	if (count == false)
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

static inline void	do_update_item(t_actions *actions, int i, char **env)
{
	if (i != 0)
		actions->item[i].redirect_in.type = input;
	if (i + 1 < actions->len)
		actions->item[i].redirect_out.type = output;
	extract_redirects(&actions->item[i], actions->item[i].exec.argv, env);
	set_action_type(&actions->item[i]);
}

static inline void	do_update_items(
	t_actions *actions, char **cmds, char **env)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < actions->len)
	{
		if (j)
			k = ++j;
		else
			k = j;
		while (cmds[j])
		{
			if (cmds[j][0] == pipes && ft_strlen(cmds[j]) == 1)
				break ;
			j++;
		}
		set_action_argv(&actions->item[i], k, j - k, cmds);
		do_update_item(actions, i, env);
		i++;
	}
}

static inline void	do_build_pipes(
	t_actions *actions, int j, char ***cmds, char **env)
{
	int	i;

	do_init_actions_items(actions, j);
	if (actions->len == false)
		return ;
	actions->pipes.item = ft_calloc(actions->len - 1, sizeof(t_pipe));
	if (actions->pipes.item)
	{
		actions->pipes.len = actions->len - 1;
		do_update_items(actions, *cmds, env);
	}
	else
	{
		free(actions->item);
		actions->len = 0;
	}
	i = 0;
	while ((*cmds)[i])
		free((*cmds)[i++]);
	free(*cmds);
}

inline t_actions	*do_build_items(
	t_actions *actions, char ***cmds, char **env)
{
	int	i;
	int	j;

	if (actions == NULL || cmds == NULL || *cmds == NULL || env == NULL)
		return (actions);
	i = 0;
	j = 0;
	while ((*cmds)[i])
	{
		if ((*cmds)[i][0] == pipes && ft_strlen((*cmds)[i]) == 1)
			j++;
		i++;
	}
	if (j == 0)
	{
		do_init_actions_items(actions, 1);
		if (actions->len == 0)
			return (actions);
		extract_redirects(actions->item, *cmds, env);
		actions->item->exec.argv = *cmds;
		set_action_type(actions->item);
	}
	else
		do_build_pipes(actions, j + 1, cmds, env);
	return (actions);
}
