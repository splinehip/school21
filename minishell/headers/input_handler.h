/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 18:15:54 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H

enum						e_controls;
enum						e_actions;
enum						e_builtins;
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
	pipes			= (int)'|',
	env_var			= (int)'$',
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
t_actions	*parse_cmd(char *cmd, char **env);
int			do_actions(t_actions *actions, char **env);
void		test_func(void);

#endif
