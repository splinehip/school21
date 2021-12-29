/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:48:39 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/29 14:21:18 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PFX_MSG "\001\033[32m\002minishell:\001\033[33m\002"
# define POSFX_MSG "\001\033[32m$\033[39m\002 "
# define PROMPT "minishell$ "

typedef struct s_sh_data
{
	char	*cmd;
	char	*msg;
	char	*res;
	char	**env;
}	t_sh_data;

int		main(int argc, char **argv, char **env);
int		init_minishell(t_sh_data *args, char **_env);
void	set_signals(short is_shell);
void	echo_ctl(char on);
int		input_loop(t_sh_data *args);
void	*xmalloc(size_t n, size_t size);
void	free_args(t_sh_data *args, int del_env);

#endif
