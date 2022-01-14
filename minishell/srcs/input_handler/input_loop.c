/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:32:13 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/14 15:20:53 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "minishell.h"
#include "input_handler.h"

static inline char	*get_prompt(char **env)
{
	char	*home;
	char	*old_res;
	char	*res;

	res = getcwd(NULL, 0);
	if (res == NULL)
		res = get_env_value("PWD", env);
	home = get_env_value("HOME", env);
	if (res && home && ft_strncmp(res, home, ft_strlen(home)) == 0)
	{
		old_res = res;
		res = ft_strljoinchr(res + ft_strlen(home), '~');
		free(old_res);
	}
	free(home);
	old_res = res;
	res = ft_strjoin(res, POSFX_MSG);
	free(old_res);
	old_res = res;
	res = ft_strjoin(PFX_MSG, res);
	free(old_res);
	if (res == NULL)
		return (PFX_MSG);
	return (res);
}

static inline void	do_add_history(t_sh_data *args)
{
	if (args->fd > 0)
		ft_putendl_fd(args->cmd, args->fd);
	add_history(args->cmd);
}

int	input_loop(t_sh_data *args)
{
	while (true)
	{
		args->msg = get_prompt(args->env);
		args->cmd = readline(args->msg);
		if (!args->cmd)
		{
			printf("exit\n");
			return (0);
		}
		if (ft_strlen(args->cmd))
			do_add_history(args);
		set_signals(0, 1);
		args->res = ft_itoa(input_handler(&args->cmd, &args->env));
		set_signals(1, 0);
		if (ft_strncmp(args->res, "1000", 4) == 0)
			return (0);
		set_env("LES", args->res, &args->env);
		free_args(args, false);
		g_interrupt = 0;
	}
}
