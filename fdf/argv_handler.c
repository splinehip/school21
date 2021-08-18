/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:33:45 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/18 21:38:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	map_size(int fd, t_fdf *vars)
{
	int		i;
	int		j;
	char	*line;
	char	**s_line;

	i = 0;
	j = 0;
	vars->map_size_x = 0;
	while (ft_gnl(fd, &line) > 0)
	{
		if (vars->map_size_x == 0)
		{
			s_line = ft_split(line, ' ');
			j = 0;
			while (s_line[j] != NULL)
				free(s_line[j++]);
			vars->map_size_x = j - 1;
			free(s_line);
		}
		i++;
		free(line);
	}
	free(line);
	close(fd);
	vars->map_size_y = i - 1;
}

static inline void	read_xyz(t_fdf *vars, char **s_line, int i)
{
	int	j;

	j = 0;
	while (s_line[j] != NULL)
	{
		if (vars->map[i] == NULL)
			vars->map[i] = ft_calloc(vars->map_size_x + 2, sizeof(int *));
		vars->map[i][j] = ft_calloc(3, sizeof(int));
		vars->map[i][j][X] = j;
		vars->map[i][j][Y] = i;
		vars->map[i][j][Z] = ft_atoi(s_line[j]);
		if (vars->map[i][j][Z] < vars->map_min_z)
			vars->map_min_z = vars->map[i][j][Z];
		if (vars->map[i][j][Z] > vars->map_max_z)
			vars->map_max_z = vars->map[i][j][Z];
		free(s_line[j++]);
	}
}

static inline void	read_map(int fd, t_fdf *vars)
{
	int		i;
	char	*line;
	char	**s_line;

	i = 0;
	line = NULL;
	while (ft_gnl(fd, &line) > 0)
	{
		s_line = ft_split(line, ' ');
		read_xyz(vars, s_line, i);
		i++;
		free(line);
		free(s_line);
	}
	free(line);
}

void	argv_handler(char *file, t_fdf *vars)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	map_size(fd, vars);
	vars->map = ft_calloc(vars->map_size_y + 2, sizeof(int *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	vars->map_min_z = 0;
	vars->map_max_z = 0;
	read_map(fd, vars);
	close(fd);
}
