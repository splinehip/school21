/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:04:24 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/07 19:38:41 by lbaela           ###   ########.fr       */
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
	// printf("GET ENV: %s\n", name);
	while (env[i])
	{
		// printf("i = %d, %s\n", i, env[i]);
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
		{
			res = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	free(name);
	// printf("GET ENV: res = %s\n", res);
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
