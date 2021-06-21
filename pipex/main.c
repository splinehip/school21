/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:46:38 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/21 11:37:35 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static inline void	redirect_io(int argc, char **argv, t_pipex args, int n)
{
	int	fd;

	if (n == 1)
	{
		fd = open(argv[1], O_RDONLY);
		dup2(fd, 0);
		close(fd);
	}
	else
		dup2(args.pipefd[0], 0);
	if (n == argc - 3)
	{
		fd = open(argv[argc - 1], O_RDWR);
		dup2(fd, 1);
		close(fd);
	}
	else
		dup2(args.pipefd[1], 1);
}

static inline int	run_child(int argc, char **argv, char **envp, t_pipex args)
{
	static int	n;
	int			pid;

	n++;
	pid = fork();
	if (pid == 0)
	{
		redirect_io(argc, argv, args, n);
		close(args.pipefd[0]);
		close(args.pipefd[1]);
		execve(args.path, args.argv, envp);
	}
	if (pid < 0)
		return (errno);
	return (0);
}

static inline int	check_files(int argc, char **argv)
{
	int	fd;

	if (argc > 4)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("%s: %s: %s\n", argv[0], argv[1], strerror(errno));
			return (errno);
		}
		close(fd);
		fd = open(argv[argc - 1], O_RDWR | O_CREAT, 0664);
		if (fd == -1)
		{
			ft_printf("%s: %s: %s\n", argv[0], argv[argc - 1], strerror(errno));
			return (errno);
		}
		close(fd);
	}
	else
	{
		ft_printf("%s: %s\n", argv[0], strerror(EINVAL));
		return (EINVAL);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		res;
	t_pipex	args;

	pipe(args.pipefd);
	args.path = NULL;
	res = check_files(argc, argv);
	while (res == 0 && argv_handler(argv, envp, &args))
	{
		res = run_child(argc, argv, envp, args);
		i = 0;
		while (args.argv[i++] != NULL)
			args.argv[i - 1] = ft_free(args.argv[i - 1], NULL);
		args.path = ft_free(args.path, NULL);
		if (res)
			ft_printf("%s: %s\n", argv[0], strerror(res));
	}
	waitpid(0, NULL, 0);
	close(args.pipefd[0]);
	close(args.pipefd[1]);
	free(args.argv[0]);
	free(args.path);
	return (res);
}
