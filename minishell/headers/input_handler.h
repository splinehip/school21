/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/21 16:21:45 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H
# define BUF_SIZE 1024

enum						e_controls;
enum						e_actions;
enum						e_builtins;
enum						e_direction;
enum						e_redirects;
typedef struct s_select		t_select;
typedef struct s_extract	t_extract;
typedef struct s_iter		t_iter;
typedef struct s_redirect	t_redirect;
typedef struct s_builtins	t_builtins;
typedef struct s_execute	t_execute;
typedef union u_args		t_a_args;
typedef struct s_actions	t_actions;

enum e_controls
{
	quote			= (int)'"',
	single_quote	= (int)'\'',
	left_corner		= (int)'<',
	right_corner	= (int)'>',
	escape			= (int)'\\',
	slash			= (int)'/',
	pipes			= (int)'|',
	dollar			= (int)'$',
	ampersand		= (int)'&',
	underscore		= (int)'_',
	space			= (int)' ',
	asterisk		= (int)'*',
	dot				= (int)'.',
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

enum e_direction
{
	single_asterisk,
	all_inn_all,
	only_start,
	only_end,
	all_end,
	start_all,
	start_all_end,
};

typedef struct s_select
{
	int		j;
	int		direction;
	char	**templated_strs;
	char	*d_name;
	char	*res;
	char	buf[BUF_SIZE];
}	t_select;

typedef struct s_extract
{
	int		j;
	int		start;
	int		end;
	int		prev_end;
	char	*res;
	char	*pchar;
	char	buf[BUF_SIZE];
}	t_extract;

typedef struct s_iter
{
	int		i;
	int		j;
	int		l;
	int		k;
	int		init_res;
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

typedef union u_args
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
int			check_cmd_sequenses(char *cmd);
char		has_opened_quotes(char *cmd, int start, int end);
char		*do_parse(char *cmd, char **env);
char		*do_parse_whith_asterisk(char *cmd, char **env);
void		do_check_quotes(char *cmd, t_iter *iter);
int			escaped(char *cmd, int i);
int			do_expand_env(char *cmd, t_iter *iter, char **env);
char		*do_expand_template(char *template_str, char **env);
int			do_update_buf(char **res, char *str, char *buf, int *j);
int			do_drop_buf(char **res, char *buf, int *j);
void		get_template_border(char *cmd, t_extract *args);
char		*get_d_name(char **env);
void		do_select_template(char *res, t_select *args);
int			pattern_matched(t_select *args);
void		pattern_matching_get_next(char **next, char *templated_str);
int			do_match_all_inn_all(t_select *args);
int			do_match_only(t_select *args, int type);
int			do_match_all_end(t_select *args);
int			do_match_start_all(t_select *args);
int			do_match_start_all_end(t_select *args);
t_actions	*do_actions_build(char *cmd, char **env);
int			do_actions(t_actions *actions, char **env);

#endif
