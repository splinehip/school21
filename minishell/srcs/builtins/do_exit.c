/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:28:25 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/29 13:23:07 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "minishell.h"
#include "actions_handler.h"

int	do_exit(t_actions action, char **env)
{
	if (!(action.args.argv[1]))
		return (1000);
	else
	{
		if (ft_isdigit(*action.args.argv[1]))
			set_env("LES", action.args.argv[1], &env);
		return (1000);
	}
}
