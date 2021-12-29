/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:49:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/29 14:23:02 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "bool.h"
#include "minishell.h"
#include "builtins.h"
#include "error_msgs.h"
#include "libft.h"

int	main(int argc, char **argv, char **_env)
{
	t_sh_data	args;
	int			res;

	(void)argv;
	if (argc == 1 && init_minishell(&args, _env))
	{
		input_loop(&args);
		printf("exit\n");
		free(args.res);
		args.res = get_env_value("LES", args.env);
		res = ft_atoi(args.res);
		free_args(&args, true);
		echo_ctl(1);
		return (res);
	}
	write(2, ERR_ARGC, ft_strlen(ERR_ARGC));
	return (1);
}
