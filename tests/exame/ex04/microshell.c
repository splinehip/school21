#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "microshell.h"

static inline void	close_pipe(int pipe_fd[2])
{
	if (pipe_fd[0])
		close(pipe_fd[0]);
	if (pipe_fd[1])
	close(pipe_fd[1]);
}

static inline unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static inline void	print_err(char *MSG, char *arg)
{
	if (arg == NULL)
		write(2, MSG, ft_strlen(MSG));
	else
	{
		write(2, MSG, ft_strlen(MSG));
		write(2, arg, ft_strlen(arg));
		write(2, "\n", 1);
	}
}

static inline void	free_actions(t_actions *actions)
{
	int i;
	int	j;
	int	k;

	i = 0;
	while (i < actions->len)
	{
		j = 0;
		while (j < actions->item[i].len)
			free(actions->item[i].cmds[j++].argv);
		free(actions->item[i++].cmds);
	}
	close_pipe(actions->pipes.pipe_one);
	close_pipe(actions->pipes.pipe_two);
	free(actions->item);
}

static inline int	create_items(t_actions *actions, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
		if (strcmp(argv[i++], ";") == 0)
			j++;
	if (j++)
	{
		actions->item = malloc(j * sizeof(*actions->item));
		actions->len = j;
	}
	else
	{
		actions->item = malloc(sizeof(*actions->item));
		actions->len = 1;
	}
	if (actions->item == NULL)
	{
		print_err(MSG_FATAL, NULL);
		return (1);
	}
	i = 0;
	while (i < actions->len)
	{
		actions->item[i].len = 0;
		actions->item[i++].cmds = NULL;
	}
	return (0);
}

static inline int	create_actions(t_actions *actions, char **argv)
{
	int	i;
	int	j;
	int	len;

	if (create_items(actions, argv))
		return (1);
	i = 0;
	j = 1;
	while (i < actions->len)
	{
		len = 0;
		while (argv[j] && strcmp(argv[j], ";") != 0)
			if (strcmp(argv[j++], "|") == 0)
				len++;
		actions->item[i].cmds = malloc((len + 1) * sizeof(*actions->item->cmds));
		if (actions->item[i].cmds == NULL)
		{
			print_err(MSG_FATAL, NULL);
			return (1);
		}
		actions->item[i++].len = len + 1;
	}
	actions->pipes.pipe_one[0] = 0;
	actions->pipes.pipe_one[1] = 0;
	actions->pipes.pipe_two[0] = 0;
	actions->pipes.pipe_two[1] = 0;
	return (0);
}

static inline int	create_argv(t_actions *actions, char **argv)
{
	int	i;
	int	k;
	int	j;
	int	start;
	int	len_argv;

	i = 0;
	j = 0;
	while (i < actions->len)
	{
		k = 0;
		start = ++j;
		len_argv = 0;
		while (argv[j] && strcmp(argv[j], ";") != 0)
		{
			if (strcmp(argv[j], "|") != 0 && strcmp(argv[j], ";") != 0)
				len_argv++;
			j++;
			if (argv[j] == NULL
				|| strcmp(argv[j], "|") == 0 || strcmp(argv[j], ";") == 0)
			{
				actions->item[i].cmds[k].argv = malloc((len_argv + 1) * sizeof(char *));
				if (actions->item[i].cmds[k].argv == NULL)
				{
					print_err(MSG_FATAL, NULL);
					return (1);
				}
				len_argv = 0;
				while (start < j)
					actions->item[i].cmds[k].argv[len_argv++] = argv[start++];
				actions->item[i].cmds[k].argv[len_argv] = NULL;
				start = j + 1;
				k++;
				len_argv = 0;
			}
		}
		i++;
	}
	return (0);
}

static inline int	init_pipes(t_actions *actions)
{
	actions->pipes.pipe_one[0] = 0;
	actions->pipes.pipe_one[1] = 0;
	actions->pipes.pipe_two[0] = 0;
	actions->pipes.pipe_two[1] = 0;
	if (pipe(actions->pipes.pipe_one) != 0)
	{
		print_err(MSG_FATAL, NULL);
		return (1);
	}
	if (pipe(actions->pipes.pipe_two) != 0)
	{
		print_err(MSG_FATAL, NULL);
		return (1);
	}
	return (0);
}

static inline int	do_exec(t_actions *actions, int i, int j, char **env)
{
	if (execve(actions->item[i].cmds[j].argv[0],
		actions->item[i].cmds[j].argv, env) < 0)
	{
		print_err(MSG_EXER, actions->item[i].cmds[j].argv[0]);
		free_actions(actions);
		exit(255);
	}
}

static inline int	do_single(t_actions *actions, int i, int j, char **env)
{
	actions->item[i].cmds[j].pid = fork();
	if (actions->item[i].cmds[j].pid == 0)
		do_exec(actions, i, j, env);
	else if (actions->item[i].cmds[j].pid < 0)
	{
		print_err(MSG_FATAL, NULL);
		return (1);
	}
	return (0);
}

static inline int	dup_pipes(t_actions *actions, int i, int j)
{
	if (init_pipes(actions))
		return (1);
	if (j % 2 == 0)
	{
		actions->item[i].cmds[j].pipe_in = dup(actions->pipes.pipe_one[0]);
		actions->item[i].cmds[j].pipe_out = dup(actions->pipes.pipe_one[1]);
	}
	else
	{
		actions->item[i].cmds[j].pipe_in = dup(actions->pipes.pipe_two[0]);
		actions->item[i].cmds[j].pipe_out = dup(actions->pipes.pipe_two[1]);
	}
	if (actions->item[i].cmds[j].pipe_in < 0
		|| actions->item[i].cmds[j].pipe_out < 0)
	{
		print_err(MSG_FATAL, NULL);
		return (1);
	}
	close_pipe(actions->pipes.pipe_one);
	close_pipe(actions->pipes.pipe_two);
	return (0);
}

static inline int	do_pipes(t_actions *actions, int i, int j, char **env)
{
	if (dup_pipes(actions, i, j))
		return (1);
	actions->item[i].cmds[j].pid = fork();
	if (actions->item[i].cmds[j].pid == 0)
	{
		if (j)
		{
			if (dup2(actions->item[i].cmds[j - 1].pipe_in, STDIN_FILENO) < 0)
			{
				print_err(MSG_FATAL, NULL);
				return (1);
			}
		}
		if (j + 1 != actions->item[i].len)
		{
			if (dup2(actions->item[i].cmds[j].pipe_out, STDOUT_FILENO) < 0)
			{
				print_err(MSG_FATAL, NULL);
				return (1);
			}
		}
		close(actions->item[i].cmds[j].pipe_in);
		close(actions->item[i].cmds[j].pipe_out);
		do_exec(actions, i, j, env);
	}
	else if (actions->item[i].cmds[j].pid < 0)
	{
		print_err(MSG_FATAL, NULL);
		return (1);
	}
	return (0);
}

static inline void	do_actions(t_actions *actions, char **env)
{
	int	i;
	int	j;
	int	st;

	i = 0;
	st = 0;
	while (i < actions->len)
	{
		j = 0;
		while (j < actions->item[i].len)
		{
			if (actions->item[i].len > 1)
			{
				if (do_pipes(actions, i, j, env))
					return ;
			}
			else
			{
				if (strcmp(actions->item[i].cmds->argv[0], "cd") == 0)
					return ;
				if (do_single(actions, i, j, env))
					return ;
			}
			if (actions->item[i].len > 1)
				close(actions->item[i].cmds[j].pipe_out);
			wait(&st);
			if (actions->item[i].len > 1)
			{
				if (j)
					close(actions->item[i].cmds[j - 1].pipe_in);
				if (j + 1 == actions->item[i].len)
					close(actions->item[i].cmds[j].pipe_in);
			}
			if (WIFEXITED(st))
				if (WEXITSTATUS(st) == 255)
					break ;
			j++;
		}
		i++;
	}

}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	j;
	int	k;
	t_actions	actions;

	if (argc == 1)
		return (0);
	if (create_actions(&actions, argv))
	{
		free_actions(&actions);
		return (1);
	}
	if (create_argv(&actions, argv))
	{
		free_actions(&actions);
		return (1);
	}
	/* i = 0;
	printf("actions.len: %i\n", actions.len);
	while (i < actions.len)
	{
		printf("action %i\n", i);
		j = 0;
		while (j < actions.item[i].len)
		{
			printf(" cmd %i\n", j);
			k = 0;
			while (actions.item[i].cmds[j].argv[k])
			{
				printf("  argv[%i]: >%s<\n", k, actions.item[i].cmds[j].argv[k]);
				k++;
			}
			printf("  argv[%i]: >%s<\n", k, actions.item[i].cmds[j].argv[k]);
			j++;
		}
		i++;
	} */
	do_actions(&actions, env);
	free_actions(&actions);
	return (0);
}