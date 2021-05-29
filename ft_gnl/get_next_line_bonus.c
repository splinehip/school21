/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:47:55 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/29 20:28:54 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static inline int	line_join_buf(char **line, t_vars *vars)
{
	char	*tmp;

	if (vars->i < vars->res && vars->buf[vars->i] != '\n')
		vars->i++;
	if (vars->i != 0)
	{
		tmp = (char *)ft_calloc(
				ft_strlen(*line) + (vars->i - vars->j) + 1, sizeof(char));
		if (tmp == NULL)
		{
			*line = _free(*line, NULL);
			vars->_return = -1;
			return (1);
		}
		ft_memcpy(tmp, *line, ft_strlen(*line));
		ft_memcpy(tmp + ft_strlen(*line),
			vars->buf + vars->j, vars->i - vars->j);
		free(*line);
		*line = tmp;
	}
	return (0);
}

static inline void	buf_handler(char **line, t_vars *vars)
{
	if (vars->res == -1 || vars->_return == -1)
	{
		if (*line != NULL)
			*line = _free(*line, NULL);
		vars->_return = -1;
		return ;
	}
	while (vars->i < vars->res - 1 && vars->buf[vars->i] != '\n')
		vars->i++;
	if (line_join_buf(line, vars))
		return ;
	if (vars->res != 0 && vars->i <= vars->res - 1 && vars->buf[vars->i] == '\n')
		vars->_return = 2;
	else if (vars->res == 0 && (vars->i == 0 || vars->i == vars->res - 1))
	{
		vars->_return = 1;
		return ;
	}
	if (vars->i <= vars->res - 1 && vars->buf[vars->i] == '\n')
		vars->i++;
	if (vars->i == vars->res)
		ft_memset(vars->buf, 0, BUFFER_SIZE);
	if (vars->i == vars->res)
		vars->i = 0;
	vars->j = vars->i;
}

static inline void	*init_vars(char **line, t_vars **vars, size_t k)
{
	if (vars != NULL && *vars != NULL)
	{
		(*vars)->k = k;
		(*vars)->_return = -1;
		*line = (char *)ft_calloc(1, sizeof(char));
		if (*line != NULL)
		{
			if ((*vars)->i == BUFFER_SIZE)
				(*vars)->i = 0;
			(*vars)->j = (*vars)->i;
			if ((*vars)->buf == NULL)
				(*vars)->buf = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
			if ((*vars)->buf != NULL)
				(*vars)->_return = 0;
			else
				*line = _free(*line, NULL);
		}
	}
	return (NULL);
}

static inline void	*vars_array_handler(char **line, int fd, t_vars **vars,
	size_t k)
{
	static t_vars	*vars_array[1024];

	if (fd == -1)
		vars_array[k] = _free(vars_array[k]->buf, vars_array[k]);
	else
	{
		while (vars_array[k] != NULL)
			k++;
		while (k < 1022 && vars_array[k + 1] != NULL)
		{
			vars_array[k] = vars_array[k + 1];
			vars_array[++k] = NULL;
		}
		k = 0;
		while (vars_array[k] != NULL && vars_array[k]->fd != fd)
			k++;
		if (k < 1022 && vars_array[k] == NULL)
		{
			vars_array[k] = (t_vars *)ft_calloc(1, sizeof(t_vars));
			if (vars_array[k] != NULL)
				vars_array[k]->fd = fd;
		}
		*vars = vars_array[k];
	}
	return (init_vars(line, vars, k));
}

int	get_next_line(int fd, char **line)
{
	t_vars	*vars;

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	vars_array_handler(line, fd, &vars, 0);
	while (vars != NULL)
	{
		if (vars->_return != -1 && vars->i == 0)
			vars->res = read(fd, vars->buf, BUFFER_SIZE);
		buf_handler(line, vars);
		if (vars->_return)
		{
			if (vars->_return == -1)
			{
				vars = vars_array_handler(NULL, -1, NULL, vars->k);
				return (-1);
			}
			else if (vars->_return == 1)
				vars = vars_array_handler(NULL, -1, NULL, vars->k);
			else if (vars->_return == 2)
				return (1);
			return (0);
		}
	}
	return (-1);
}
