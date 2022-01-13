/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:47:08 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/13 14:50:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "actions_handler.h"

t_actions	*do_actions_build(t_actions *actions, char *cmd, char ***env)
{
	char	**splited_cmd;

	splited_cmd = split_cmd(cmd, *env);
	if (splited_cmd == NULL)
		return (actions);
	return (do_build_items(actions, &splited_cmd, *env));
}
