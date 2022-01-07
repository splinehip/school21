/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:50 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/07 20:18:43 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "actions_handler.h"

typedef struct s_env	t_env;

struct s_env
{
	char	*name;
	char	*val;
	t_env	*next;
};

int		do_pwd(t_action action);
int		do_exit(t_action action, char **env);
int		do_echo(t_action action);
int		do_cd(t_action action, char **env);
int		do_unset(t_action action, char **env);
int		do_export(t_action action, char **env);
void	set_env(char *name, char *value, char ***env);
void	unset_env(char *name, char **env);
char	*get_env(char *name, char **env);
char	*get_env_value(char *name, char **env);

#endif
