/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:01:34 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/06 21:37:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_HANDLER_H
# define ACTIONS_HANDLER_H
# define READ_INPUT_FILE ".read_input.tmp"
# include "enums.h"

typedef struct s_pipe		t_pipe;
typedef struct s_pipes		t_pipes;
typedef struct s_redirect	t_redirect;
typedef struct s_redirects	t_redirects;
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

typedef struct s_redirects
{
	int			len;
	t_redirect	*item;
}	t_redirects;

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
	t_execute	exec;
	t_redirects	redirects;
}	t_action;

typedef struct s_actions
{
	int			len;
	t_action	*item;
	t_pipes		pipes;
}	t_actions;

t_actions	*do_actions_build(t_actions *actions, char *cmd, char **env);
void		add_redirects(t_redirects *redirects, int type, char *target);
void		extract_redirects(t_redirects *redirects, char **str);
int			do_actions(t_actions *actions, char **env);
int			do_action_run(t_action *action, char **env);
void		do_redirects(t_action action, char **env);
int			do_redirects_builtin(t_action action);
int			get_redirect_fd(t_redirect redirect);
int			is_valid_action_path(t_action *action, char **env);

#endif
