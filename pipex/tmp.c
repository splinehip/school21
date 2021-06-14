	child = fork();
	if (child == -1)
	{
		perror("fork");
		return (1);
	}
	if (child == 0)
		return (run_child(argv, envp, path));
	else
	{
		if (path != NULL)
		{
			status = 0;
			while (path[status] != NULL)
				free(path[status++]);
			free(path);
		}
		waitpid(-1, &status, 0);
		if (WIFSIGNALED(status))
			ft_printf("\nRECIVE SIG: %i\n", WTERMSIG(status));
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
		{
			perror("execve");
			return (WEXITSTATUS(status));
		}
	}
