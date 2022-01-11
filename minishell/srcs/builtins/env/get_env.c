/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:04:24 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 23:15:31 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "bool.h"
#include "enums.h"
#include "builtins.h"

inline int	get_env_i(char *name, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], name) == success)
			break ;
		else if (ft_strncmp(env[i], name, ft_strlen(name)) == success)
		{
			tmp = ft_strchr(env[i], eq);
			if (tmp)
			{
				if ((int)ft_strlen(name) == tmp - env[i])
					break ;
			}
		}
		i++;
	}
	if (env[i])
		return (i);
	return (-1);
}

inline char	*get_env(char *name, char **env)
{
	int	i;

	i = get_env_i(name, env);
	if (i >= 0)
		return (ft_strdup(env[i]));
	return (NULL);
}

inline char	*get_env_value(char *name, char **env)
{
	char	*res;
	char	*tmp;
	char	*get_env_res;

	if (name == NULL)
		return (NULL);
	res = NULL;
	if (*name == question)
		get_env_res = get_env("LES", env);
	else
		get_env_res = get_env(name, env);
	if (get_env_res)
	{
		tmp = ft_strchr(get_env_res, eq);
		if (tmp)
		{
			res = ft_strdup(tmp + 1);
			free(get_env_res);
		}
	}
	return (res);
}

inline char	*get_env_name(char *env_i)
{
	char	*tmp;

	if (env_i == NULL)
		return (NULL);
	tmp = ft_strchr(env_i, eq);
	if (tmp)
		return (ft_substr(env_i, 0, tmp - env_i));
	else
		return (ft_strdup(env_i));
}
