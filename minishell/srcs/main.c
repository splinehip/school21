/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:49:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 12:07:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"
#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*cmd;

	(void)argc;
	(void)argv;
	while (true)
	{
		cmd = readline("minishel:$ ");
		input_handler(cmd, env);
		free(cmd);
	}
	return (0);
}
