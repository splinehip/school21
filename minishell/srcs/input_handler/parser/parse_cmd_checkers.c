/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:11:31 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/14 14:20:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "input_handler.h"
#include "minishell.h"

static inline char	escaped_eof(char *cmd)
{
	if (*cmd && cmd[ft_strlen(cmd) - 1] == escape
		&& escaped(cmd, ft_strlen(cmd) - 1) == false)
		return (escape);
	return (0);
}

static inline char	more_two_sequenses_controls(
	char *cmd, char opened_qoute, int i, int j)
{
	while (cmd[i] != ends)
	{
		if (cmd[i] == quote || cmd[i] == single_quote)
		{
			if (opened_qoute == false && escaped(cmd, i) == false)
				opened_qoute = cmd[i];
			else if (opened_qoute && opened_qoute == single_quote
				&& cmd[i] == opened_qoute)
				opened_qoute = 0;
			else if (opened_qoute
				&& opened_qoute == quote && escaped(cmd, i) == false)
				opened_qoute = 0;
		}
		else if ((cmd[i] == ampersand || cmd[i] == pipes)
			&& opened_qoute == false)
		{
			j = i;
			while (cmd[i + 1] == cmd[j])
				i++;
			if (i - j > 1)
				return (cmd[i]);
		}
		i++;
	}
	return (false);
}

static inline int	has_opened_parenth(
	char *cmd, char parenth, char opened_quote, int i)
{
	while (cmd[i] != ends)
	{
		if (cmd[i] == quote || cmd[i] == single_quote)
		{
			if (cmd[i] == single_quote && opened_quote == single_quote)
				opened_quote = 0;
			else if (cmd[i] == quote && opened_quote == quote
				&& escaped(cmd, i) == false)
				opened_quote = 0;
			else if (opened_quote == 0 && escaped(cmd, i) == false)
				opened_quote = cmd[i];
		}
		if (opened_quote == false
			&& cmd[i] == open_parenth && escaped(cmd, i) == false)
			parenth++;
		else if (opened_quote == false
			&& cmd[i] == close_parenth && escaped(cmd, i) == false)
		{
			parenth--;
			if (parenth < 0)
				return (1);
		}
		i++;
	}
	return (parenth != 0);
}

static inline int	empty_heredoc_or_redirect(char *cmd)
{
	if (cmd == NULL || *cmd == ends)
		return (unsuccess);
	if (((*cmd == l_crnr || *cmd == r_crnr) && ft_strlen(cmd) == 1)
		|| (ft_strcmp(cmd, "<<") == success || ft_strcmp(cmd, ">>") == success)
		|| (cmd[ft_strlen(cmd) - 1] == l_crnr
			|| cmd[ft_strlen(cmd) - 1] == r_crnr))
	{
		print_err(MSG_ERR_SYNATX, NULL, false);
		return (unsuccess);
	}
	return (success);
}

inline int	check_cmd_sequenses(char *cmd)
{
	if (escaped_eof(cmd) == escape)
	{
		print_err(MSG_ERR_CMD_EEOF, NULL, false);
		return (false);
	}
	if (has_opened_quotes(cmd, 0, ft_strlen(cmd)))
	{
		print_err(MSG_ERR_CMD_UQ, NULL,
			has_opened_quotes(cmd, 0, ft_strlen(cmd)));
		return (false);
	}
	if (more_two_sequenses_controls(cmd, 0, 0, 0))
	{
		print_err(MSG_ERR_MORE2CNTRLS, NULL,
			more_two_sequenses_controls(cmd, 0, 0, 0));
		return (false);
	}
	if (has_opened_parenth(cmd, 0, 0, 0))
	{
		print_err(MSG_ERR_CMD_HAS_UP, NULL, false);
		return (false);
	}
	if (empty_heredoc_or_redirect(cmd))
		return (false);
	return (true);
}
