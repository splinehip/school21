/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:50 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 20:45:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "actions_handler.h"

int		do_pwd(t_action action);
int		do_exit(t_action action, char ***env);
int		do_echo(t_action action);
int		do_cd(t_action action, char ***env);
int		do_unset(t_action action, char ***env);
int		do_export(t_action action, char ***env);
void	set_env(char *name, char *value, char ***env);
void	unset_env(char *name, char **env);
char	*get_env(char *name, char **env);
char	*get_env_value(char *name, char **env);
int		get_env_i(char *name, char **env);
char	*get_env_name(char *env_i);
void	do_print_env(int fd, char **env);
int		do_env(t_action action, char **env);

#endif
