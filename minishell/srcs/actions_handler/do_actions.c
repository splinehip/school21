/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:28:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/27 12:05:02 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		i++;
	}
	free(actions);
}

int	do_actions(t_actions *actions, char **env)
{
	int	i;
	int	res;

	(void)env;
	if (actions == NULL)
		return (1);
	i = 0;
	while (actions[i].end != true)
	{
		ft_printf("\naction: %i\n type: %s\n argv:", i,
			get_action_type_name(actions[i]));
		res = 0;
		while (actions[i].args.argv[res])
			ft_printf(" %s", actions[i].args.argv[res++]);
		ft_printf("\n");
		res = 0;
		if (actions[i].args.redirect)
		{
			while (actions[i].args.redirect[res].end != true)
			{
				ft_printf(" redirect %i: type: %s, target: %s\n", res,
					get_redirect_type_name(actions[i].args.redirect[res]),
					actions[i].args.redirect[res].target);
				res++;
			}
		}
		else
			ft_printf(" redirects: none\n");
		i++;
	}
	if (actions->type == exit_built)
		res = exit_built;
	free_actions(actions);
	return (res);
}
