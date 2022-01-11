/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:00:26 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 23:10:40 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

#include "libft.h"
#include "bool.h"
#include "mesages.h"
#include "input_handler.h"
#include "actions_handler.h"
#include "minishell.h"

struct s_extract_iter
{
	int		i;
	char	**str;
};

static inline void	parse_read_input_target(t_redirect *redirect, char **env)
{
	char	*tmp;

	if (redirect->target)
	{
		tmp = redirect->target;
		redirect->target = parse_cmd(redirect->target, env, false);
		free(tmp);
	}
}

static inline void	do_read_input(
	t_redirect *redirect, char *target, char **env)
{
	char	*tmp;
	char	*readline_res;

	readline_res = NULL;
	*redirect->target = 0;
	while (target && g_interrupt == false)
	{
		readline_res = readline(MSG_RL_SUBINPUT);
		// printf("readline: %s\n", readline_res);
		if (ft_strcmp(readline_res, target) == 0)
			break ;
		if (readline_res)
		{
			tmp = readline_res;
			readline_res = ft_strjoinchr(readline_res, endl);
			free(tmp);
			tmp = redirect->target;
			redirect->target = ft_strjoin(redirect->target, readline_res);
			free(tmp);
		}
		free(readline_res);
	}
	free(target);
	free(readline_res);
	parse_read_input_target(redirect, env);
}

static inline void	update_str(char **str, int i, int j)
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
		update_str(iter->str, iter->i, iter->i + 2);
	}
	else
	{
		free(redirect->target);
		redirect->target = ft_strtrim(iter->str[iter->i], "<>");
		update_str(iter->str, iter->i, iter->i + 1);
	}
	if (redirect->type == read_input)
	{
		set_signals(3, 0);
		do_read_input(redirect, ft_strdup(redirect->target), env);
		set_signals(1, 0);
	}
}

inline void	extract_redirects(t_action *action, char **str, char **env)
{
	struct s_extract_iter	iter;

	iter.i = 0;
	iter.str = str;
	while (str && str[iter.i])
	{
		if (str[iter.i][0] == left_corner)
		{
			if (str[iter.i][1] == left_corner)
				do_extract(&action->redirect_in, &iter, read_input, env);
			else
				do_extract(&action->redirect_in, &iter, input, env);
			iter.i--;
		}
		else if (str[iter.i][0] == right_corner)
		{
			if (str[iter.i][1] == right_corner)
				do_extract(&action->redirect_out, &iter, output_append, env);
			else
				do_extract(&action->redirect_out, &iter, output, env);
			iter.i--;
		}
		iter.i++;
	}
}
