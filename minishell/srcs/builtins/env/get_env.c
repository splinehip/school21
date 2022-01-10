/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:04:24 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/10 21:02:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "enums.h"
#include "builtins.h"

char	*get_env(char *name, char **env)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	name = ft_strjoinchr(name, eq);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
		{
			res = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	free(name);
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
