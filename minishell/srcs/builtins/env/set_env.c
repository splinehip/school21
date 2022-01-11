/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 16:05:51 by lbaela           ###   ########.fr       */
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
	while ((*env)[i])
		i++;
	new = ft_calloc(i + 2, sizeof(char *));
	if (new == NULL)
		return ;
	i = 0;
	while ((*env)[i])
	{
		new[i] = (*env)[i];
		i++;
	}
	if (!value)
		new[i++] = ft_strdup(name);
	else
	{
		name = ft_strjoinchr(name, '=');
		value = ft_strjoin(name, value);
		new[i++] = value;
		free(name);
	}
	tmp = *env;
	*env = new;
	free(tmp);
}

static inline void	update(char *name, char *value, char **env)
{
	int		i;
	char	*env_var;
	int		len;

	i = 0;
	if (!value)
		return ;
	len = ft_strlen(name);
	while (env[i] && (ft_strncmp(env[i], name, len) != 0
			&& (env[i][len] == 0 || env[i][len] == eq)))
		i++;
	name = ft_strjoinchr(name, '=');
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
