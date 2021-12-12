/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:04:24 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/12 17:06:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtins.h"

char	*get_env(char *name, char **env)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	name = ft_strjoinchr(name, '=');
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
	tmp = get_env(name, env);
	if (tmp)
		res = ft_strdup(ft_strchr(tmp, '=') + 1);
	free(tmp);
	return (res);
}
