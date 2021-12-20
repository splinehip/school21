/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:48:39 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 17:19:52 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PFX_MSG "\001\033[32m\002minishell:\001\033[33m\002"
# define POSFX_MSG "\001\033[32m$\033[39m\002 "
# define PROMPT "minishell$ "

int		main(int argc, char **argv, char **env);
void	set_signals(short is_shell);
void	echo_ctl(char on);

#endif
