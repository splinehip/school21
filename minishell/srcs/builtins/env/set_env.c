/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 23:12:31 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "builtins.h"

static inline void	upgrade(
	char *name, char *value, char ***new, char ***env)
{
	int		i;
	char	**tmp;
	char	*env_var;

	i = 0;
	while ((*env)[i])
		i++;
	name = ft_strjoinchr(name, '=');
	env_var = ft_strjoin(name, value);
	(*new)[i] = ft_strdup(env_var);
	(*new)[++i] = NULL;
	tmp = *env;
	*env = *new;
	free(tmp);
	free(name);
	free(env_var);
}

static inline void	append(char *name, char *value, char ***env)
{
	int		i;
	char	**new;

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
	new[i] = NULL;
	upgrade(name, value, &new, env);
}

static inline void	update(char *name, char *value, char **env)
{
	int		i;
	char	*env_i;
	char	*env_var;

	i = 0;
	name = ft_strjoinchr(name, '=');
	while (env[i] && ft_strncmp(env[i], name, ft_strlen(name)) != 0)
		i++;
	env_i = env[i];
	env_var = ft_strjoin(name, value);
	if (env_var != NULL)
	{
		env[i] = env_var;
		free(name);
		free(env_i);
		return ;
	}
	free(name);
	return ;
}

void	set_env(char *name, char *value, char ***env)
{
	char	*tmp;

	if (name == NULL || value == NULL)
		return ;
	tmp = get_env(name, *env);
	if (tmp == NULL)
		return (append(name, value, env));
	free(tmp);
	update(name, value, *env);
}
