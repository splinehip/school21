/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:28:25 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/05 16:23:00 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	do_exit(t_action action, char **env)
{
	printf("exit\n");
	if (!(action.exec.argv[1]))
		return (1000);
	else
	{
		if (is_number(action.exec.argv[1]) && !(action.exec.argv[2]))
			set_env("LES", action.exec.argv[1], &env);
		else if (!is_number(action.exec.argv[1]))
		{
			printf("minishell: exit: %s: numeric argument required\n",
				action.exec.argv[1]);
			set_env("LES", "2", &env);
		}
		else
		{
			printf("minishell: exit: too many arguments\n");
			return (1);
		}
		return (1000);
	}
}
