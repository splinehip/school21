/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:38:42 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/29 13:06:46 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"
#include "minishell.h"

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

int	init_minishell(t_sh_data *args, char **_env)
{
	args->msg = NULL;
	args->cmd = NULL;
	args->res = NULL;
	env_dup(&args->env, _env);
	set_env("LES", "0", &args->env);
	set_signals(1);
	return (1);
}
