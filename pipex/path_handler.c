/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:28:26 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/21 12:14:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static inline int	find_path(char **paths, char *name, char *cmd,
								t_pipex *args)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*path;

	i = 0;
	while (paths[i] != NULL)
	{
		tmp = ft_strjoinchr(paths[i++], '/');
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		fd = open(path, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			args->path = path;
			return (1);
		}
		free(path);
	}
	ft_printf("%s: %s: %s\n", name, cmd, strerror(errno));
	return (0);
}

static inline int	get_path(char **paths, char *name, char *cmd, t_pipex *args)
{
	int		fd;

	if (*cmd == '/' || *cmd == '.')
	{
		fd = open(cmd, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			args->path = ft_strdup(cmd);
			return (1);
		}
		ft_printf("%s: %s: %s\n", name, cmd, strerror(errno));
		return (0);
	}
	return (find_path(paths, name, cmd, args));
}

int	path_handler(char **envp, char *name, char *cmd, t_pipex *args)
{
	int		i;
	int		res;
	char	**paths;

	if (envp == NULL || cmd == NULL || args == NULL)
		return (0);
	paths = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (paths == NULL)
		return (0);
	res = get_path(paths, name, cmd, args);
	i = 0;
	while (paths[i] != NULL)
		free(paths[i++]);
	free(paths);
	return (res);
}
