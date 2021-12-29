/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:01:25 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/29 13:01:19 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bool.h"
#include "minishell.h"

void	free_args(t_sh_data *args, int del_env)
{
	int	i;

	if (del_env == true)
	{
		i = 0;
		while (args->env[i] != NULL)
			free(args->env[i++]);
		free(args->env);
	}
	free(args->msg);
	free(args->cmd);
	free(args->res);
	args->msg = NULL;
	args->cmd = NULL;
	args->res = NULL;
}
