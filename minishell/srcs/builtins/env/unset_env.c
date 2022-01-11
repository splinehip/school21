/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:02:46 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 19:03:10 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "builtins.h"

void	unset_env(char *name, char **env)
{
	int		i;
	char	*tmp;

	if (name == NULL || env == NULL)
		return ;
	i = get_env_i(name, env);
	if (i < 0)
		return ;
	tmp = env[i];
	while (env[i])
	{
		env[i] = env[i + 1];
		i++;
	}
	free(tmp);
}
