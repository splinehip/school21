/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:01:34 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/29 13:51:07 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_HANDLER_H
# define ACTIONS_HANDLER_H
# include "enums.h"

typedef struct s_redirect	t_redirect;
typedef struct s_execute	t_execute;
typedef struct s_actions	t_actions;

typedef struct s_redirect
{
	int		type;
	int		end;
	char	*target;
}	t_redirect;

typedef struct s_execute
{
	char		*path;
	char		**argv;
	t_redirect	*redirect;
}	t_execute;

typedef struct s_actions
{
	int			type;
	int			end;
	t_execute	args;
}	t_actions;

t_actions	*do_actions_build(char *cmd, char **env);
void		extract_redirects(t_actions *actions, char **str);
void		add_redirects(t_actions *actions, int type, char *target);
int			do_actions(t_actions *actions, char **env);
void		do_redirects(t_redirect *redirects, char **env);
int			is_valid_action_path(t_actions *action, char **env);

#endif
