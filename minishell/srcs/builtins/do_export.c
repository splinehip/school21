/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:57:04 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/10 20:16:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "minishell.h"

int	do_export(t_action action, char **env)
{
	int		fd;
	int		i;
	int		j;
	char	***penv;

	j = 0;
	while (env[j])
		j++;
	printf("export: env: %s\n", env[j - 1]);
	printf("export: env: %p\n", env[j + 1]);
	penv = (char ***)env[j + 1];
	printf("export: env: %p\n", penv);
	printf("export: env: %p\n", *penv);
	printf("export: env: %p\n", env);
	printf("export: env: %s\n", (*penv)[0]);
	i = 1;
	fd = do_redirects_builtin(action);
	if (!action.exec.argv[i])
	{
		while (env[i])
		{
			write(fd, EXPORT_PREPEND, ft_strlen(EXPORT_PREPEND));
			write(fd, env[i], ft_strlen(env[i]));
			write(fd, "\n", 1);
			i++;
		}
	}
	else
	{
		while (action.exec.argv[i])
		{
			set_env(action.exec.argv[i++], "NULL", penv);
			printf("export %i: env: %p\n", i, *penv);
		}
	}
	if (fd > 2)
		close(fd);
	return (0);
}
