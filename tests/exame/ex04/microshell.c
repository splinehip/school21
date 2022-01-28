#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "microshell.h"

void	free_actions(t_actions *actions)
{
	int i;
	int	j;

	i = 0;
	while (i < actions->len)
	{
		j = 0;
		while (j < actions->item[i].len)
			free(actions->item[i].cmds[j++].argv);
		free(actions->item[i++].cmds);
	}
	free(actions->item);
}

static inline void	create_items(t_actions *actions, char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (argv[++i])
		if (argv[i + 1] == NULL || (strcmp(argv[i], ";") == 0
			&& strcmp(argv[i + 1], ";") != 0))
			len++;
	if (len == 0)
		return ;
	actions->item = xmalloc(actions, len * sizeof(*actions->item));
	actions->len = len;
	i = 0;
	while (i < actions->len)
	{
		actions->item[i].len = 0;
		actions->item[i++].cmds = NULL;
	}
}

static inline void	create_cmds(t_actions *actions, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (i < actions->len)
	{
		len = 0;
		while (argv[++j] && strcmp(argv[j], ";") != 0)
			if (argv[j + 1] == NULL || strcmp(argv[j + 1], ";") == 0
				|| strcmp(argv[j], "|") == 0)
				len++;
		if (len)
		{
			actions->item[i].cmds = xmalloc(actions,
				len * sizeof(*actions->item->cmds));
			actions->item[i++].len = len;
		}
		if (argv[j] == NULL)
			break ;
	}
}

static inline void	create_argv(t_actions *actions, char **argv)
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
			if (strcmp(argv[j++], "|") != 0)
				len_argv++;
			if (argv[j] == NULL
				|| strcmp(argv[j], "|") == 0 || strcmp(argv[j], ";") == 0)
			{
				actions->item[i].cmds[k].argv = xmalloc(actions,
					++len_argv * sizeof(char *));
				len_argv = 0;
				while (start < j)
					actions->item[i].cmds[k].argv[len_argv++] = argv[start++];
				actions->item[i].cmds[k].argv[len_argv] = NULL;
				actions->item[i].cmds[k].pid = 0;
				actions->item[i].cmds[k].pipe_fd[in] = 0;
				actions->item[i].cmds[k].pipe_fd[out] = 0;
				if (argv[j] != NULL && strcmp(argv[j], "|") != 0)
					i++;
				k++;
				start++;
				len_argv = 0;
			}
		}
		if (argv[j] == NULL)
			break ;
	}
}

static inline void	do_exec(t_actions *actions, int i, int j, char **env)
{
	if (execve(actions->item[i].cmds[j].argv[0],
		actions->item[i].cmds[j].argv, env) < 0)
	{
		print_err(MSG_EXER, actions->item[i].cmds[j].argv[0]);
		free_actions(actions);
		exit(255);
	}
}

static inline void	do_single(t_actions *actions, int i, int j, char **env)
{
	actions->item[i].cmds[j].pid = fork();
	if (actions->item[i].cmds[j].pid == 0)
		do_exec(actions, i, j, env);
	else if (actions->item[i].cmds[j].pid < 0)
		exit_fatal(actions);
}

static inline void	do_pipes(t_actions *actions, int i, int j, char **env)
{
	actions->item[i].cmds[j].pid = fork();
	if (actions->item[i].cmds[j].pid == 0)
	{
		if (j)
			if (dup2(actions->item[i].cmds[j - 1].pipe_fd[in], STDIN_FILENO) < 0)
				exit_fatal(actions);
		if (j + 1 != actions->item[i].len)
			if (dup2(actions->item[i].cmds[j].pipe_fd[out], STDOUT_FILENO) < 0)
				exit_fatal(actions);
		close(actions->item[i].cmds[j].pipe_fd[in]);
		close(actions->item[i].cmds[j].pipe_fd[out]);
		do_exec(actions, i, j, env);
	}
	else if (actions->item[i].cmds[j].pid < 0)
		exit_fatal(actions);
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
				if (pipe(actions->item[i].cmds[j].pipe_fd))
					exit_fatal(actions);
				do_pipes(actions, i, j, env);
			}
			else
			{
				if (strcmp(actions->item[i].cmds->argv[0], "cd") == 0)
					do_cd(actions->item[i].cmds[j].argv);
				else
					do_single(actions, i, j, env);
			}
			if (actions->item[i].len > 1)
				close(actions->item[i].cmds[j].pipe_fd[out]);
			waitpid(-1, &st, 0);
			if (actions->item[i].len > 1)
			{
				if (j)
					close(actions->item[i].cmds[j - 1].pipe_fd[in]);
				if (j + 1 == actions->item[i].len)
					close(actions->item[i].cmds[j].pipe_fd[in]);
			}
			/* if (WIFEXITED(st))
				if (WEXITSTATUS(st) == 255)
					break ; */
			j++;
		}
		i++;
	}

}

int	main(int argc, char **argv, char **env)
{
	t_actions	actions;

	if (argc == 1)
		return (0);
	actions.len = 0;
	actions.item = NULL;
	create_items(&actions, argv);
	create_cmds(&actions, argv);
	create_argv(&actions, argv);
	//print_actions(actions);
	do_actions(&actions, env);
	free_actions(&actions);
	return (0);
}
