#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef struct s_pipex
{
	char	*path;
	char	*argv[255];
}			t_pipex;

int	path_handler(char **envp, char *name, char *cmd, t_pipex *args);
int	argv_handler(char **argv, char **envp, t_pipex *args);

#endif
