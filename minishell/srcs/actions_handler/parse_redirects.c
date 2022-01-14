/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:00:26 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/14 03:51:57 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "bool.h"
#include "mesages.h"
#include "error_msgs.h"
#include "input_handler.h"
#include "actions_handler.h"
#include "minishell.h"

struct s_extract_iter
{
	int		i;
	char	**str;
};

static inline void	update_strs(char **str, int i, int j)
{
	char	*tmp;

	tmp = str[i];
	while (str[j])
		str[i++] = str[j++];
	str[i] = NULL;
	free(tmp);
}

static inline void	do_extract(
	t_redirect *redirect, struct s_extract_iter *iter, int type, char **env)
{
	redirect->type = type;
	if (ft_strlen(iter->str[iter->i]) == 1
		|| (ft_strlen(iter->str[iter->i]) == 2
			&& iter->str[iter->i][0] == iter->str[iter->i][1]))
	{
		redirect->target = iter->str[iter->i + 1];
		update_strs(iter->str, iter->i, iter->i + 2);
	}
	else
	{
		free(redirect->target);
		redirect->target = ft_strtrim(iter->str[iter->i], "<>");
		update_strs(iter->str, iter->i, iter->i + 1);
	}
	if (redirect->type == read_input)
	{
		set_signals(3, 0);
		do_read_input(redirect, ft_strdup(redirect->target), env);
		set_signals(1, 0);
	}
}

static inline void	do_select_extract_type(
	t_action *action, struct s_extract_iter *iter, char **env)
{
	char	*tmp;

	if (*iter->str[iter->i] == l_crnr)
	{
		if (iter->str[iter->i][1] == l_crnr)
			do_extract(&action->redirect_in, iter, read_input, env);
		else
			do_extract(&action->redirect_in, iter, input, env);
		iter->i--;
	}
	else if (*iter->str[iter->i] == r_crnr)
	{
		if (iter->str[iter->i][1] == r_crnr)
			do_extract(&action->redirect_out, iter, output_append, env);
		else
			do_extract(&action->redirect_out, iter, output, env);
		iter->i--;
	}
	else if (*iter->str[iter->i] == quote
		|| *iter->str[iter->i] == single_quote)
	{
		tmp = iter->str[iter->i];
		iter->str[iter->i] = parse_cmd(iter->str[iter->i], env, false);
		free(tmp);
	}
}

inline void	extract_redirects(t_action *action, char **str, char **env)
{
	struct s_extract_iter	iter;

	iter.i = 0;
	iter.str = str;
	while (str && str[iter.i])
	{
		do_select_extract_type(action, &iter, env);
		iter.i++;
	}
}
