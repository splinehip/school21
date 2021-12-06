/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 12:00:39 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H

enum								e_controls;
enum								e_actions;
enum								e_builtins;
typedef struct s_actions			t_actions;
typedef struct s_redirect			t_redirect;
typedef struct s_args_expand		t_args_expand;
typedef struct s_args_builtins		t_args_builtins;
typedef struct s_args_execute		t_args_execute;
typedef struct s_args_exec_pipe		t_args_exc_pipe;

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

typedef struct s_actions
{
	int		type;
	void	*args;
}	t_actions;

typedef struct s_redirect
{
	int		type;
	char	*target;
}	t_redirect;

typedef struct s_args_expand
{
	char	*name;
}	t_args_expand;

typedef struct s_args_builtins
{
	int		name;
	char	**args;
	char	**options;
}	t_args_builtins;

typedef struct s_args_execute
{
	int			path;
	char		**args;
	t_redirect	*redirect;
}	t_args_execute;

typedef struct s_args_exec_pipe
{
	t_args_execute	*args;
}	t_args_exec_pipe;

int			input_handler(char *cmd, char **env);
t_actions	*parser(char *cmd);
void		test_func(void);

#endif
