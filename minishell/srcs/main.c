/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:49:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 23:27:09 by cflorind         ###   ########.fr       */
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

static inline char	*get_msg(char **env)
{
	char	*tmp;
	char	*res;

	tmp = get_env_value("PWD", env);
	res = ft_strjoin(PFX_MSG, tmp);
	free(tmp);
	tmp = res;
	res = ft_strjoin(res, "$ ");
	free(tmp);
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

int	main(int argc, char **argv, char **_env)
{
	char	*cmd;
	char	*msg;
	char	*res;
	char	**env;

	(void)argc;
	(void)argv;
	env_dup(&env, _env);
	set_env("LES", "0", &env);
	while (true)
	{
		msg = get_msg(env);
		cmd = readline(msg);
		if (cmd != NULL && ft_strlen(cmd))
			add_history(cmd);
		res = ft_itoa(input_handler(cmd, env));
		set_env("LES", res, &env);
		free(res);
		free(msg);
		free(cmd);
	}
	return (0);
}
