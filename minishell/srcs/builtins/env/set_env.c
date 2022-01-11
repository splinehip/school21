/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 23:15:08 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"

static inline void	move_env(char **new, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		new[i] = env[i];
		i++;
	}
}

static inline void	append(char *name, char *value, char ***env)
{
	int		i;
	char	**new;
	char	**tmp;

	if (name == NULL || value == NULL || env == NULL)
		return ;
	i = 0;
	while ((*env)[i])
		i++;
	new = ft_calloc(i + 2, sizeof(char *));
	if (new == NULL)
		return ;
	move_env(new, *env);
	if (ft_strlen(value) > 0)
	{
		name = ft_strjoinchr(name, eq);
		value = ft_strjoin(name, value);
		free(name);
		new[i] = value;
	}
	else
		new[i] = ft_strdup(name);
	tmp = *env;
	*env = new;
	free(tmp);
}

static inline void	update(char *name, char *value, char **env)
{
	int		i;
	char	*env_var;

	if (name == NULL || value == NULL || env == NULL)
		return ;
	i = get_env_i(name, env);
	if (i < 0)
		return ;
	if (ft_strlen(value) > 0)
	{
		name = ft_strjoinchr(name, eq);
		env_var = ft_strjoin(name, value);
		free(name);
	}
	else
		env_var = ft_strjoin(name, value);
	if (env_var != NULL)
	{
		free(env[i]);
		env[i] = env_var;
	}
}

void	set_env(char *name, char *value, char ***env)
{
	char	*tmp;

	if (name == NULL)
		return ;
	tmp = get_env(name, *env);
	if (tmp == NULL)
		append(name, value, env);
	else
	{
		free(tmp);
		update(name, value, *env);
	}
}
