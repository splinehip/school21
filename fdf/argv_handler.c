/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:33:45 by cflorind          #+#    #+#             */
/*   Updated: 2021/08/25 15:08:43 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	map_size(int fd, t_fdf *vars, int i, int j)
{
	char	*line;
	char	**s_line;

	vars->map_size_x = 0;
	while (ft_gnl(fd, &line) > 0)
	{
		s_line = ft_split(line, ' ');
		j = 0;
		while (s_line[j] != NULL)
			free(s_line[j++]);
		if (vars->map_size_x == 0)
			vars->map_size_x = j - 1;
		else if (vars->map_size_x != j - 1)
		{
			close(fd);
			return (0);
		}
		free(s_line);
		i++;
		free(line);
	}
	free(line);
	close(fd);
	vars->map_size_y = i - 1;
	return (1);
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

static inline int	check_map(char *file, t_fdf *vars)
{
	int	fd;

	fd = open(file, __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_printf("%s: it's are directory not a file!\n", file);
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s: %s\n", file, strerror(errno));
		return (0);
	}
	if (map_size(fd, vars, 0, 0) == 0)
	{
		ft_printf("%s: Invalid map!\n", file);
		return (0);
	}
	return (1);
}

int	argv_handler(char *file, t_fdf *vars)
{
	int	fd;

	if (check_map(file, vars) == 0)
		return (0);
	vars->map = ft_calloc(vars->map_size_y + 2, sizeof(int *));
	fd = open(file, O_RDONLY);
	vars->map_min_z = 0;
	vars->map_max_z = 0;
	read_map(fd, vars);
	close(fd);
	return (1);
}
