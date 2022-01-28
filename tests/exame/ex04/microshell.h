#ifndef MICROSHELL_H
# define MICROSHELL_H
# define MSG_FATAL "error: fatal\n"
# define MSG_CDBA "error: cd: bad arguments\n"
# define MSG_CDERR "error: cd: cannot change directory to "
# define MSG_EXER "error: cannot execute "

typedef struct s_pipes
{
	int pipe_one[2];
	int pipe_two[2];
}	t_pipes;


typedef struct s_cmd
{
	int		pid;
	int		pipe_in;
	int		pipe_out;
	char	**argv;
}	t_cmd;

typedef struct s_item
{
	int		len;
	t_cmd	*cmds;
}	t_item;


typedef struct s_actions
{
	int		len;
	t_item	*item;
	t_pipes	pipes;
}	t_actions;

int				main(int argc, char **argv, char **env);
unsigned int	ft_strlen(char *str);
void			print_err(char *MSG, char *arg);
void			close_pipe(int pipe_fd[2]);
void			free_actions(t_actions *actions);
void			*xmalloc(t_actions *actions, size_t n);
void			print_actions(t_actions actions);

#endif
