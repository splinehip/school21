/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:28:25 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/04 13:35:12 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "minishell.h"
#include "actions_handler.h"

int	do_exit(t_action action, char **env)
{
	if (!(action.exec.argv[1]))
		return (1000);
	else
	{
		if (ft_isdigit(*action.exec.argv[1]))
			set_env("LES", action.exec.argv[1], &env);
		return (1000);
	}
}
