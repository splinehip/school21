/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:29:31 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/12 11:45:21 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"
#include "minishell.h"

static void	handler_shell(int s)
{
	if (s == SIGQUIT && MAC_OS)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	else if (s == SIGINT)
	{
		rl_on_new_line();
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	handler_parent(int s)
{
	if (s == SIGQUIT || s == SIGINT)
	{
	}
}

static void	handler_child(int s)
{
	if (s == SIGQUIT)
		printf("Quit: %d\n", s);
	else if (s == SIGINT)
		printf("\n");
}

static void	handler_heredoc(int s)
{
	static struct termios	key_termios;

	if (s == SIGQUIT && MAC_OS)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	else if (s == SIGINT)
	{
		tcgetattr(0, &key_termios);
		key_termios.c_cc[VEOF] = 3;
		key_termios.c_cc[VINTR] = 4;
		tcsetattr(0, TCSANOW, &key_termios);
		g_interrupt = 1;
		if (MAC_OS)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

void	set_signals(short is_shell, short ctl)
{
	sig_t					h_fun;
	static struct termios	key_termios;

	tcgetattr(0, &key_termios);
	key_termios.c_cc[VEOF] = 4;
	key_termios.c_cc[VINTR] = 3;
	tcsetattr(0, TCSANOW, &key_termios);
	if (is_shell == 1)
		h_fun = &handler_shell;
	else if (is_shell == 2)
		h_fun = &handler_parent;
	else if (is_shell == 3)
		h_fun = &handler_heredoc;
	else
		h_fun = &handler_child;
	echo_ctl(ctl);
	signal(SIGINT, h_fun);
	signal(SIGQUIT, h_fun);
}
