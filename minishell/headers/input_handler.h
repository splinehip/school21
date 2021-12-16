/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/16 14:51:09 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H
# define BUF_SIZE 1024

enum						e_controls;
enum						e_actions;
enum						e_builtins;
typedef struct s_extract	t_extract;
typedef struct s_iter		t_iter;
typedef struct s_redirect	t_redirect;
typedef struct s_builtins	t_builtins;
typedef struct s_execute	t_execute;
typedef union args			t_a_args;
typedef struct s_actions	t_actions;

enum e_controls
{
	quote			= (int)'"',
	single_quote	= (int)'\'',
	left_corner		= (int)'<',
	right_corner	= (int)'>',
	escape			= (int)'\\',
	pipes			= (int)'|',
	dollar			= (int)'$',
	space			= (int)' ',
	asterisk		= (int)'*',
	tab				= (int)'\t',
	endl			= (int)'\n',
	vtab			= (int)'\v',
	cr				= (int)'\r',
	ends			= (int)'\0',
};

enum e_actions
{
	expand,
	builtin,
	execute,
	exec_pipe,
};

enum e_builtins
{
	echo,
	cd,
	pwd,
	export,
	unset,
	env,
	exit_built,
};

enum e_redirects
{
	input,
	read_input,
	output,
	output_append,
};

typedef struct s_extract
{
	int		start;
	int		end;
	int		prev_end;
	char	**res;
	char	*pchar;
}	t_extract;

typedef struct s_iter
{
	int		i;
	int		j;
	int		l;
	int		k;
	int		in_qoutes;
	char	buf[BUF_SIZE];
	char	*name;
	char	*value;
	char	*res;
}	t_iter;

typedef struct s_redirect
{
	int		type;
	char	*target;
}	t_redirect;

typedef struct s_builtins
{
	int		name;
	char	**args;
	char	**options;
}	t_builtins;

typedef struct s_execute
{
	char		**argv;
	t_redirect	*redirect;
}	t_execute;

typedef union args
{
	t_builtins	b_args;
	t_execute	exc_args;
}	t_a_args;

typedef struct s_actions
{
	int			type;
	t_a_args	*args;
}	t_actions;

int			input_handler(char *cmd, char **env);
char		*parse_cmd(char *cmd, char **env);
char		has_opened_quots(char *cmd, int start, int end);
char		*do_parse(char *cmd, char **env);
char		*do_parse_whith_asterisk(char *cmd, char **env);
void		do_check_quotes(char *cmd, t_iter *iter);
int			escaped(char *cmd, int i);
int			do_expand_env(char *cmd, t_iter *iter, char **env);
int			do_drop_buf(t_iter *iter);
void		get_template_border(char *cmd, t_extract *args);
t_actions	*do_actions_build(char *cmd, char **env);
int			do_actions(t_actions *actions, char **env);

#endif
