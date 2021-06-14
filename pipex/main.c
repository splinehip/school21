/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:46:38 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/14 19:49:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static inline int	run_child(char **envp, t_pipex args)
{
	int	status;

	if (fork() == 0)
		execve(args.path, args.argv, envp);
	else
	{
		waitpid(0, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (errno);
	}
	perror("fork");
	return (1);
}

static inline int	check_argv(int argc, char **argv)
{
	int	fd;

	if (argc > 4)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("%s: %s: %s\n", argv[0], argv[1], strerror(errno));
			return (1);
		}
		close(fd);
		fd = open(argv[argc - 1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("%s: %s: %s\n", argv[0], argv[argc - 1], strerror(errno));
			return (1);
		}
		close(fd);
	}
	else
	{
		ft_printf("%s: %s\n", argv[0], strerror(EINVAL));
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		res;
	t_pipex	args;

	args.path = NULL;
	res = check_argv(argc, argv);
	while (!res && argv_handler(argv, envp, &args))
	{
		res = run_child(envp, args);
		i = 0;
		while (args.argv[i] != NULL)
		{
			args.argv[i] = ft_free(args.argv[i], NULL);
			i++;
		}
		args.path = ft_free(args.path, NULL);
		if (res)
			ft_printf("%s: %s\n", argv[0], strerror(res));
	}
	free(args.argv[0]);
	free(args.path);
	return (res);
}
