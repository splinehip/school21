/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:49:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 13:27:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"
#include "minishell.h"

static inline char	*get_msg(char **env)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", 3) == 0)
		{
			res = ft_strjoin(PFX_MSG, env[i] + 4);
			tmp = res;
			res = ft_strjoin(res, "$ ");
			free(tmp);
			if (res == NULL)
				return (PFX_MSG);
			return (res);
		}
		i++;
	}
	return (PFX_MSG);
}

int	main(int argc, char **argv, char **env)
{
	char	*cmd;
	char	*msg;

	(void)argc;
	(void)argv;
	while (true)
	{
		msg = get_msg(env);
		cmd = readline(msg);
		if (cmd != NULL && ft_strlen(cmd))
			add_history(cmd);
		input_handler(cmd, env);
		free(msg);
		free(cmd);
	}
	return (0);
}
