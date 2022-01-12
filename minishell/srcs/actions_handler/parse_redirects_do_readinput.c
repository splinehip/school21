/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects_do_readinput.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:16:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/12 15:17:36 by cflorind         ###   ########.fr       */
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
#include "error_msgs.h"

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

static inline void	do_update_target(t_redirect *redirect, char *readline_res)
{
	char	*tmp;

	readline_res = ft_strjoinchr(readline_res, endl);
	tmp = redirect->target;
	redirect->target = ft_strjoin(redirect->target, readline_res);
	free(tmp);
}

inline void	do_read_input(t_redirect *redirect, char *target, char **env)
{
	char	*readline_res;

	readline_res = NULL;
	*redirect->target = 0;
	while (target && g_interrupt == false)
	{
		readline_res = readline(MSG_RL_SUBINPUT);
		if (!readline_res && g_interrupt == false)
			print_err(MSG_ERR_HEREDOC, target, 0);
		if (ft_strcmp(readline_res, target) == 0)
			break ;
		if (readline_res)
			do_update_target(redirect, readline_res);
		free(readline_res);
	}
	free(target);
	free(readline_res);
	parse_read_input_target(redirect, env);
}
