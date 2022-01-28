#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "microshell.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_err(char *MSG, char *arg)
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

void	exit_fatal(t_actions *actions)
{
	print_err(MSG_FATAL, NULL);
	free_actions(actions);
	exit(1);
}

void	*xmalloc(t_actions *actions, size_t n)
{
	void	*res;

	res = malloc(n);
	if (res == NULL)
		exit_fatal(actions);
	return (res);
}

void	do_cd(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i != 2 || (i == 2 && strcmp(argv[1], "-") == 0))
		print_err(MSG_CDBA, NULL);
	else if (chdir(argv[1]))
		print_err(MSG_CDERR, argv[1]);
}

void	print_actions(t_actions actions)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	printf("actions.len: %i\n", actions.len);
	while (i < actions.len)
	{
		printf("action %i, actions.item[%i].len: %i\n", i, i, actions.item[i].len);
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
	}
}
