/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:04:24 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 20:37:34 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtins.h"

char	*get_env(char *name, char **env)
{
	int		i;

	i = 0;
	name = ft_strjoinchr(name, '=');
	while (env[i])
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
		{
			free(name);
			return (ft_strdup(env[i]));
		}
		i++;
	}
	return (NULL);
}

char	*get_env_value(char *name, char **env)
{
	int	i;

	i = 0;
	name = ft_strjoinchr(name, '=');
	while (env[i])
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
		{
			free(name);
			return (ft_strdup(env[i] + ft_strlen(name) + 1));
		}
		i++;
	}
	return (NULL);
}
