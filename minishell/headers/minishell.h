/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:48:39 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 11:01:25 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifdef __APPLE__
#  define MAC_OS 1
# else
#  define MAC_OS 0
# endif
# define PFX_MSG		"\001\033[32m\002minishell:\001\033[33m\002"
# define POSFX_MSG		"\001\033[32m$\033[39m\002 "
# define PROMPT			"minishell$ "
# define SHBIN			"/minishell"
# define HISTORY_FILE	"/tmp/.minishell_history"
# define EXPORT_PREPEND	"declare -x "

typedef struct s_sh_data
{
	int		fd;
	char	*cmd;
	char	*msg;
	char	*res;
	char	**env;
}	t_sh_data;

short	g_interrupt;

int		main(int argc, char **argv, char **env);
int		init_minishell(t_sh_data *args, char **_env);
void	set_signals(short is_shell, short ctl);
void	echo_ctl(char on);
int		input_loop(t_sh_data *args);
void	free_args(t_sh_data *args, int del_env);
void	print_err(char *main, char	*word, char ch);

#endif
