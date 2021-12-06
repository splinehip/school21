/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:50 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 21:42:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		do_pwd(char **env);
void	set_env(char *name, char *value, char ***env);
char	*get_env(char *name, char **env);
char	*get_env_value(char *name, char **env);

#endif
