/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:47:55 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/09 14:14:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			*line = ft_free(*line, NULL);
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
			*line = ft_free(*line, NULL);
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
				*line = ft_free(*line, NULL);
		}
	}
	return (NULL);
}

static inline void	*vars_array_handler(char **line, int fd, t_vars **vars,
	size_t k)
{
	static t_vars	*vars_array[1024];

	if (fd == -1)
		vars_array[k] = ft_free(vars_array[k]->buf, vars_array[k]);
	else if (*vars == NULL || (*vars != NULL && (*vars)->fd != fd))
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

/*
Arguments:
fd is the file descriptor to read.
line is a pointer to a char pointer to which the address of the result will be
assigned.

Return values:
The function returns 0 when the end of the file is reached, otherwise 1. If in
During the operation of the function, an error occurred and returned -1.

Description:
The function reads the file into a buffer and assigns the line pointer to the
address of the result in which contains the string. Each subsequent call to the
function "returns" next line from file. Until the end of the file is reached,
the function returns 1, upon reaching the end of the file and "returning" the
last line, it returns 0. When error returns -1.
*/
int	ft_gnl(int fd, char **line)
{
	static t_vars	*vars;

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
