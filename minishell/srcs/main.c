/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:49:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 17:19:38 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"
#include "minishell.h"

struct s_main
{
	char	*cmd;
	char	*msg;
	char	*res;
	char	**env;
};

static inline char	*get_msg(char **env)
{
	char	*home;
	char	*old_res;
	char	*res;

	res = get_env_value("PWD", env);
	home = get_env_value("HOME", env);
	if (ft_strncmp(res, home, ft_strlen(home)) == 0)
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

static inline void	env_dup(char ***env, char **_env)
{
	int		i;

	i = 0;
	while (_env[i++])
		;
	*env = malloc(i * sizeof(char *));
	if (*env == NULL)
	{
		printf("minishel: can't allocate memory for env.\n");
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
			printf("minishel: can't duplicate env.\n");
			exit(1);
		}
	}
}

static inline void	free_args(struct s_main *args, int del_env)
{
	int	i;

	if (del_env == true)
	{
		i = 0;
		while (args->env[i] != NULL)
			free(args->env[i++]);
		free(args->env);
	}
	free(args->msg);
	free(args->cmd);
	free(args->res);
	args->res = NULL;
}

int	main(int argc, char **argv, char **_env)
{
	struct s_main	args;

	(void)argc;
	(void)argv;
	env_dup(&args.env, _env);
	set_env("LES", "0", &args.env);
	set_signals(1);
	while (true)
	{
		args.msg = get_msg(args.env);
		args.cmd = readline(args.msg);
		if (!args.cmd)
		{
			printf("\033M\033[%d`exit\n", (int)ft_strlen(args.msg) - 25);
			free_args(&args, true);
			echo_ctl(1);
			return (0);
		}
		if (args.cmd != NULL && ft_strlen(args.cmd))
			add_history(args.cmd);
		args.res = ft_itoa(input_handler(args.cmd, args.env));
		set_env("LES", args.res, &args.env);
		free(args.res);
		args.res = get_env_value("LES", args.env);
		if (ft_strncmp(args.res, "6", 1) == 0)
		{
			free_args(&args, true);
			exit(6);
		}
		free_args(&args, false);
	}
	echo_ctl(1);
	return (0);
}
