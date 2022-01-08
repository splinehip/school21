/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:49:58 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/07 12:09:16 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "bool.h"
#include "minishell.h"
#include "builtins.h"
#include "error_msgs.h"
#include "libft.h"

void	print_err(char *main, char	*word, char ch)
{
	int	stdout;

	stdout = dup(STDOUT_FILENO);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	if (main && word)
		printf(main, word);
	else if (main && ch)
		printf(main, ch);
	else
		printf("%s", main);
	dup2(stdout, STDOUT_FILENO);
	close(stdout);
}

int	main(int argc, char **argv, char **_env)
{
	t_sh_data	args;
	int			res;

	(void)argv;
	if (argc == 1 && init_minishell(&args, _env))
	{
		input_loop(&args);
		close(args.fd);
		free(args.res);
		args.res = get_env_value("LES", args.env);
		res = ft_atoi(args.res);
		free_args(&args, true);
		echo_ctl(1);
		return (res);
	}
	print_err(ERR_ARGC, NULL, 0);
	return (1);
}
