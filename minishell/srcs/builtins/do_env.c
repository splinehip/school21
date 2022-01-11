/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:16:49 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 20:45:47 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "builtins.h"
#include "bool.h"

int	do_env(t_action action, char **env)
{
	int	i;
	int	fd;
	int	saved_stdout;

	if (env == NULL)
		return (unsuccess);
	fd = do_redirects_builtin(action);
	if (fd > 0)
	{
		saved_stdout = dup(STDOUT_FILENO);
		dup2(fd, STDOUT_FILENO);
		i = 0;
		while (env[i])
			printf("%s\n", env[i++]);
		dup2(saved_stdout, STDOUT_FILENO);
	}
	else
	{
		i = 0;
		while (env[i])
			printf("%s\n", env[i++]);
	}
	if (fd > 0)
		close(fd);
	return (success);
}
