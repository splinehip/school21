/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/07 20:00:10 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "builtins.h"

static inline void	append(char *name, char *value, char ***env)
{
	int		i;
	char	**new;
	char	**tmp;

	i = 0;
	while ((*env)[i++])
		;
	new = malloc((i + 1) * sizeof(char *));
	if (new == NULL)
		return ;
	i = 0;
	while ((*env)[i])
	{
		new[i] = (*env)[i];
		i++;
	}
	name = ft_strjoinchr(name, '=');
	value = ft_strjoin(name, value);
	new[i] = value;
	new[++i] = NULL;
	tmp = *env;
	*env = new;
	free(tmp);
	free(name);
}

static inline void	update(char *name, char *value, char **env)
{
	int		i;
	char	*env_var;

	i = 0;
	// printf("set_env - append\n");
	name = ft_strjoinchr(name, '=');
	while (env[i] && ft_strncmp(env[i], name, ft_strlen(name)) != 0)
		i++;
	env_var = ft_strjoin(name, value);
	if (env[i] != NULL && env_var != NULL)
	{
		free(env[i]);
		env[i] = env_var;
	}
	free(name);
}

void	set_env(char *name, char *value, char ***env)
{
	char	*tmp;

	if (name == NULL || value == NULL)
		return ;
	// printf("here 1\n");
	tmp = get_env(name, *env);
	// printf("here 2\n");
	if (tmp == NULL)
		return (append(name, value, env));
	free(tmp);
	// printf("set_env - update\n");
	update(name, value, *env);
}
