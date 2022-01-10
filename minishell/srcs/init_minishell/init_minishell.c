/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:38:42 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/10 19:08:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <readline/history.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"
#include "minishell.h"
#include "error_msgs.h"

static inline void	env_dup(t_sh_data *args, char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	args->env = ft_calloc(i + 2, sizeof(char *));
	if (args->env == NULL)
	{
		print_err(MSG_ERR_MEM, NULL, 0);
		exit(1);
	}
	i = 0;
	while (env[i])
	{
		args->env[i] = ft_strdup(env[i]);
		if (args->env[i] == NULL)
		{
			while (i >= 0)
				free(args->env[i--]);
			print_err(MSG_ERR_ENV, NULL, 0);
			exit(1);
		}
		i++;
	}
	args->env[++i] = (char *)&args->env;
	printf("env_dup: args->env: %p\n", args->env[i]);
}

static inline void	load_history(t_sh_data *args)
{
	int		res;
	char	*line;

	args->fd = open(HISTORY_FILE, O_CREAT | O_APPEND | O_RDWR, 0664);
	if (args->fd < 0)
	{
		print_err(MSG_ERR_INVAL_HIS_FD, NULL, false);
		return ;
	}
	line = NULL;
	while (true)
	{
		res = ft_gnl(args->fd, &line);
		if (res > 0)
			add_history(line);
		else if (res <= 0)
		{
			free(line);
			break ;
		}
		free(line);
		line = NULL;
	}
}

int	init_minishell(t_sh_data *args, char **env)
{
	args->msg = NULL;
	args->cmd = NULL;
	args->res = NULL;
	args->env = NULL;
	load_history(args);
	env_dup(args, env);
	int	i;
	i = 0;
	while (args->env[i])
		i++;
	printf("init: args->env: %p\n", args->env[i + 1]);
	set_env("LES", "0", args->env);
	i = 0;
	while (args->env[i])
		i++;
	printf("init after set: args->env: %p\n", args->env[i + 1]);
	set_signals(1, 0);
	return (1);
}
