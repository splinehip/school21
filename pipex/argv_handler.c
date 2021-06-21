/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:01:29 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/21 11:41:31 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static inline int	set_args(char *s, t_pipex *args)
{
	int		i;
	char	**res;

	i = 0;
	res = ft_split(s, ' ');
	if (res == NULL)
		return (0);
	while (res[i] != NULL)
	{
		args->argv[i + 1] = res[i];
		i++;
	}
	args->argv[i + 1] = NULL;
	free(res);
	return (1);
}

static inline int	get_args(char **argv, char **envp, t_pipex *args, int *i)
{
	char	*tmp;

	tmp = ft_strchr(argv[*i], ' ');
	if (tmp != NULL)
		*tmp = 0;
	if (argv[*i][0] == '/')
		args->argv[0] = ft_strdup(ft_strrchr(argv[*i], '/') + 1);
	else
		args->argv[0] = ft_strdup(argv[*i]);
	if (path_handler(envp, argv[0], argv[*i], args))
	{
		if (tmp != NULL)
			return (set_args(tmp + 1, args));
		else
			args->argv[1] = NULL;
		return (1);
	}
	return (0);
}

int	argv_handler(char **argv, char **envp, t_pipex *args)
{
	static int	i;

	if (argv == NULL || envp == NULL || args == NULL)
		return (0);
	if (i == 0)
		i++;
	if (argv[++i + 1] == NULL)
	{
		i = 0;
		return (0);
	}
	return (get_args(argv, envp, args, &i));
}
