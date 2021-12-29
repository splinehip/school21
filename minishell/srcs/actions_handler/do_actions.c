/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:28:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/29 13:50:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "actions_handler.h"

static inline char	*get_builtins_name(int type)
{
	if (type == echo)
		return ("echo");
	if (type == cd)
		return ("cd");
	if (type == pwd)
		return ("pwd");
	if (type == export)
		return ("export");
	if (type == unset)
		return ("unset");
	if (type == env)
		return ("env");
	if (type == exit_built)
		return ("exit_built");
	return ("undefind");
}

static inline char	*get_action_type_name(t_actions action)
{
	if (action.type == execute)
		return ("execute");
	else
		return (get_builtins_name(action.type));
}

static inline char	*get_redirect_type_name(t_redirect redirect)
{
	if (redirect.type == input)
		return ("input");
	if (redirect.type == read_input)
		return ("read_input");
	if (redirect.type == output)
		return ("output");
	if (redirect.type == output_append)
		return ("output_append");
	return ("undefined");
}

static inline void	free_actions(t_actions *actions)
{
	int	i;
	int	j;

	i = 0;
	while (actions && actions[i].end != true)
	{
		j = 0;
		while (actions[i].args.redirect
			&& actions[i].args.redirect[j].end != true)
			free(actions[i].args.redirect[j++].target);
		free(actions[i].args.redirect);
		j = 0;
		while (actions[i].args.argv && actions[i].args.argv[j])
			free(actions[i].args.argv[j++]);
		free(actions[i].args.argv);
		free(actions[i].args.path);
		i++;
	}
	free(actions);
}

static inline void	print_actions(t_actions *actions, int i, int j)
{
	i = 0;
	while (actions[i].end != true)
	{
		ft_printf("\naction: %i\n type: %s\n argv:", i,
			get_action_type_name(actions[i]));
		j = 0;
		while (actions[i].args.argv[j])
			ft_printf(" %s", actions[i].args.argv[j++]);
		ft_printf("\n");
		j = 0;
		if (actions[i].args.redirect)
		{
			while (actions[i].args.redirect[j].end != true)
			{
				ft_printf(" redirect %i: type: %s, target: %s\n", j,
					get_redirect_type_name(actions[i].args.redirect[j]),
					actions[i].args.redirect[j].target);
				j++;
			}
		}
		else
			ft_printf(" redirects: none\n");
		i++;
	}
}

static inline int	do_action_run(t_actions action, char **env)
{
	int		res;
	char	*path;
	pid_t	pid;

	res = sucsses;
	action.args.path = NULL;
	if (is_valid_action_path(&action, env) == false)
		return (127);
	if (action.args.path)
		path = action.args.path;
	else
		path = action.args.argv[0];
	pid = fork();
	if (pid == sucsses)
		execve(path, action.args.argv, env);
	else
		waitpid(pid, &res, 0);
	return (res);
}

static inline int	do_action_builtin(t_actions action, char **env)
{
	int	res;

	(void)action;
	(void)env;
	res = sucsses;
	if (action.type == exit_built)
		res = exit_built;
	return (res);
}

int	do_actions(t_actions *actions, char **env)
{
	int	i;
	int	res;

	if (actions == NULL)
		return (unsucsses);
	i = 0;
	res = sucsses;
	while (actions[i].end == false)
	{
		if (actions[i].type == execute)
			res = do_action_run(actions[i], env);
		else
			res = do_action_builtin(actions[i], env);
		i++;
	}
	free_actions(actions);
	return (res);
}
