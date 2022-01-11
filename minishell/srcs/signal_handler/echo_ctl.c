/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_ctl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:38:09 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/11 17:35:45 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>

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
