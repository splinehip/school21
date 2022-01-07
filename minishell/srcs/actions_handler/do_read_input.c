/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:20:16 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/07 17:40:17 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <readline/readline.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "mesages.h"
#include "input_handler.h"
#include "actions_handler.h"

static inline void	update_res(char *readline_res, int fd, char **env)
{
	char	*parsed_res;

	parsed_res = parse_cmd(readline_res, env, false);
	if (parsed_res)
		ft_putendl_fd(parsed_res, fd);
	free(parsed_res);
}

static inline int	do_break(
	char *target, char **readline_res, int fd, int *read_input_res)
{
	if (ft_strncmp(*readline_res, target, ft_strlen(target)) == success)
	{
		close(fd);
		free(*readline_res);
		*read_input_res = true;
		return (true);
	}
	return (false);
}

inline void	do_read_input(
	char *target, int *read_input_res, int *pipe_in, char **env)
{
	int		fd;
	char	*readline_res;

	fd = success;
	while (fd == success)
		fd = access(BLOCK_READ_INPUT_FILE, F_OK);
	fd = open(BLOCK_READ_INPUT_FILE, O_CREAT, 0664);
	*read_input_res = false;
	if (fd > 0)
	{
		close(fd);
		fd = open(READ_INPUT_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0664);
		while (fd > 0)
		{
			readline_res = readline(MSG_RL_SUBINPUT);
			if (do_break(target, &readline_res, fd, read_input_res))
				break ;
			update_res(readline_res, fd, env);
			free(readline_res);
		}
		if (*read_input_res == false)
			perror(MSG_PROG_NAME);
	}
	*pipe_in = false;
	unlink(BLOCK_READ_INPUT_FILE);
}
