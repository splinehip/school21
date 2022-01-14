/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:01:34 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/14 11:21:58 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_HANDLER_H
# define ACTIONS_HANDLER_H
# include "enums.h"

typedef struct s_pipe		t_pipe;
typedef struct s_pipes		t_pipes;
typedef struct s_redirect	t_redirect;
typedef struct s_execute	t_execute;
typedef struct s_action		t_action;
typedef struct s_actions	t_actions;

typedef struct s_pipe
{
	int	pipe[2];
}	t_pipe;

typedef struct s_pipes
{
	int		len;
	t_pipe	*item;
}	t_pipes;

typedef struct s_redirect
{
	int		type;
	char	*target;
}	t_redirect;

typedef struct s_execute
{
	char		*path;
	char		**argv;
}	t_execute;

typedef struct s_action
{
	int			pid;
	int			type;
	int			pipe_in;
	int			pipe_out;
	int			pipe_read_input[2];
	t_execute	exec;
	t_redirect	redirect_in;
	t_redirect	redirect_out;
}	t_action;

typedef struct s_actions
{
	int			len;
	t_action	*item;
	t_pipes		pipes;
}	t_actions;

t_actions	*do_actions_build(t_actions *actions, char *cmd, char ***env);
t_actions	*do_build_items(t_actions *actions, char ***cmds, char **env);
void		extract_redirects(t_action *action, char **str, char **env);
void		set_action_argv(t_action *action, int start, int len, char **cmds);
void		set_action_type(t_action *action);
void		do_read_input(t_redirect *redirect, char *target, char **env);
int			do_actions(t_actions *actions, char ***env);
int			do_action_run(t_action *action, char ***env);
void		do_redirects(t_action action);
int			do_redirects_builtin(t_action action);
int			get_redirect_fd(t_redirect redirect);
int			is_valid_action_path(t_action *action, char **env);
void		child_exit_handler(t_actions *actions, int *exit_status);

#endif
