/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:04:24 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 16:02:23 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "enums.h"
#include "builtins.h"

static void	update_end_of_str(char *name, char ch)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == ch)
		{
			name[i] = 0;
			break ;
		}
		i++;
	}
}

char	*get_env(char *name, char **env)
{
	int		i;
	char	*name_0;
	char	*res;

	i = 0;
	res = NULL;
	name_0 = ft_strdup(name);
	update_end_of_str(name_0, eq);
	name = ft_strjoinchr(name, eq);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0
			|| ft_strncmp(env[i], name_0, ft_strlen(name_0) + 1) == 0)
		{
			res = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	free(name);
	free(name_0);
	return (res);
}

char	*get_env_value(char *name, char **env)
{
	char	*tmp;
	char	*res;

	res = NULL;
	if (name == NULL)
		return (res);
	if (*name == question)
		tmp = get_env("LES", env);
	else
		tmp = get_env(name, env);
	if (tmp)
		res = ft_strdup(ft_strchr(tmp, eq) + 1);
	free(tmp);
	return (res);
}
