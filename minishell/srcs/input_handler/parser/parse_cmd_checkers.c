/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:11:31 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/06 12:17:30 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "input_handler.h"
#include "minishell.h"

inline char	has_opened_quotes(char *cmd, int start, int end)
{
	char	*quote_type;

	quote_type = NULL;
	while (start <= end && cmd[start] != ends)
	{
		if (cmd[start] == quote || cmd[start] == single_quote)
		{
			if (quote_type == NULL)
			{
				if (escaped(cmd, start) == false)
					quote_type = &cmd[start];
			}
			else if (cmd[start] == *quote_type)
			{
				if (*quote_type == single_quote)
					quote_type = NULL;
				else if (escaped(cmd, start) == false)
					quote_type = NULL;
			}
		}
		start++;
	}
	if (quote_type)
		return (*quote_type);
	return (false);
}

static inline char	escaped_eof(char *cmd)
{
	if (cmd[ft_strlen(cmd) - 1] == escape
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

inline int	check_cmd_sequenses(char *cmd)
{
	if (escaped_eof(cmd) == escape)
	{
		print_err(MSG_ERR_CMD_EEOF, NULL, 0);
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
		print_err(MSG_ERR_CMD_HAS_UP, NULL, 0);
		return (false);
	}
	return (true);
}
