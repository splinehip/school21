/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:29:31 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/20 18:24:17 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"

void	echo_ctl(char on)
{
	struct termios	tstate;

	tcgetattr(0, &tstate);
	if (on)
		tstate.c_lflag |= ECHOCTL;
	else
		tstate.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &tstate);
}

static void	handler_shell(int s)
{
	if (s == SIGQUIT)
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
		printf("This is a child 's signl handler: SIGINT\n");
}

void	set_signals(short is_shell)
{
	sig_t	h_fun;

	if (is_shell == 1)
		h_fun = &handler_shell;
	else if (is_shell == 2)
		h_fun = &handler_parent;
	else
		h_fun = &handler_child;
	echo_ctl(0);
	signal(SIGINT, h_fun);
	signal(SIGQUIT, h_fun);
}
