/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:19:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 20:39:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "builtins.h"

static inline void	upgrade_env(
	char *name, char *value, char **new, char ***env)
{
	int		i;
	char	*tmp_name;
	char	*env_var;
	char	**tmp;

	i = 0;
	while (new[i])
		i++;
	tmp_name = ft_strjoinchr(name, '=');
	env_var = ft_strjoin(tmp_name, value);
	if (env_var != NULL)
		new[i++] = ft_strdup(env_var);
	else
		new[i++] = ft_strdup("1");
	new[i] = NULL;
	tmp = *env;
	*env = new;
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp_name);
	free(env_var);
}

static inline void	append_env(char *name, char *value, char ***env)
{
	int		i;
	char	**new;

	i = 0;
	while ((*env)[i++])
		;
	new = malloc(i * sizeof(char **));
	if (new == NULL)
		return ;
	i = 0;
	while ((*env)[i])
	{
		new[i] = (*env)[i];
		i++;
	}
	new[i] = NULL;
	upgrade_env(name, value, new, env);
}

static inline void	update_env(char *name, char *value, char **env)
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

void	set_env(char *name, char *value, char **env)
{
	char	*tmp;

	if (name == NULL || value == NULL)
		return ;
	tmp = get_env(name, env);
	if (tmp == NULL)
		return (append_env(name, value, &env));
	free(tmp);
	update_env(name, value, env);
}
