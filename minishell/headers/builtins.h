/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:50 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/03 13:12:13 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "actions_handler.h"

int		do_pwd(char **env);
int		do_exit(t_action action, char **env);
void	set_env(char *name, char *value, char ***env);
void	unset_env(char *name, char **env);
char	*get_env(char *name, char **env);
char	*get_env_value(char *name, char **env);

#endif
