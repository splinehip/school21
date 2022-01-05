/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:28:25 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/05 18:25:53 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "error_msgs.h"
#include "libft.h"
#include "builtins.h"
#include "minishell.h"
#include "actions_handler.h"

static int	is_number(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

static int	close_fd(int fd)
{
	if (fd)
		close(fd);
	return (0);
}

int	do_exit(t_action action, char **env)
{
	if (action.pipe_out || action.pipe_in)
		return (close_fd(action.pipe_out));
	printf("exit\n");
	if (!(action.exec.argv[1]))
		return (1000);
	else
	{
		if (is_number(action.exec.argv[1]) && !(action.exec.argv[2]))
			set_env("LES", action.exec.argv[1], &env);
		else if (!is_number(action.exec.argv[1]))
		{
			printf(MSG_ERR_EXIT_NUM, action.exec.argv[1]);
			set_env("LES", "2", &env);
		}
		else
		{
			printf(MSG_ERR_EXIT_ARGS);
			return (1);
		}
		return (1000);
	}
}
