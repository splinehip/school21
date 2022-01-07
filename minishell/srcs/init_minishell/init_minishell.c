/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:38:42 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/07 17:03:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <readline/history.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"
#include "minishell.h"
#include "error_msgs.h"

static inline void	env_dup(char ***env, char **_env)
{
	int		i;

	i = 0;
	while (_env[i++])
		;
	*env = malloc(i * sizeof(char *));
	if (*env == NULL)
	{
		print_err(MSG_ERR_MEM, NULL, 0);
		exit(1);
	}
	(*env)[--i] = NULL;
	while (--i >= 0)
	{
		(*env)[i] = ft_strdup(_env[i]);
		if ((*env)[i] == NULL)
		{
			while ((*env)[++i] != NULL)
				free((*env)[i]);
			print_err(MSG_ERR_ENV, NULL, 0);
			exit(1);
		}
	}
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
		free(line);
		line = NULL;
		res = ft_gnl(args->fd, &line);
		if (res <= 0)
		{
			free(line);
			break ;
		}
	}
}

int	init_minishell(t_sh_data *args, char **_env)
{
	args->msg = NULL;
	args->cmd = NULL;
	args->res = NULL;
	args->env = NULL;
	load_history(args);
	env_dup(&args->env, _env);
	set_env("LES", "0", &args->env);
	set_signals(1, 0);
	return (1);
}
