/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:33:45 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/17 18:27:53 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	map_size(int fd, t_fdf *vars)
{
	int		i;
	int		j;
	char	*line;
	char	**s_line;

	i = 0;
	j = 0;
	while (ft_gnl(fd, &line) > 0)
	{
		s_line = ft_split(line, ' ');
		j = 0;
		while (s_line[j] != NULL)
			free(s_line[j++]);
		i += j;
		free(line);
		free(s_line);
	}
	free(line);
	close(fd);
	vars->map_size_x = j - 1;
	vars->map_size_y = i - 1;
	return (i);
}

static inline void	get_xyz(t_fdf *vars, char **s_line, int j)
{
	int			k;
	static int	i;

	k = 0;
	while (s_line[k] != NULL)
	{
		vars->map[i] = ft_calloc(3, sizeof(int));
		vars->map[i][X] = k;
		vars->map[i][Y] = j;
		vars->map[i][Z] = ft_atoi(s_line[k]);
		if (vars->map[i][Z] < vars->map_min_z)
			vars->map_min_z = vars->map[i][Z];
		if (vars->map[i][Z] > vars->map_max_z)
			vars->map_max_z = vars->map[i][Z];
		i++;
		free(s_line[k++]);
	}
}

static inline void	read_map(int fd, t_fdf *vars)
{
	int		j;
	char	*line;
	char	**s_line;

	j = 0;
	line = NULL;
	while (ft_gnl(fd, &line) > 0)
	{
		s_line = ft_split(line, ' ');
		get_xyz(vars, s_line, j);
		j++;
		free(line);
		free(s_line);
	}
	free(line);
}

void	argv_handler(char *file, t_fdf *vars)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	vars->map = ft_calloc(map_size(fd, vars) + 1, sizeof(int *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	vars->map_min_z = 0;
	vars->map_max_z = 0;
	read_map(fd, vars);
	close(fd);
}
