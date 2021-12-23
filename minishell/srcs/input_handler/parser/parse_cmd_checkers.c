/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:11:31 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/23 11:07:41 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "input_handler.h"

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

static inline int	has_opened_parenthes(
	char *cmd, char parenthes, char opened_quote, int i)
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
			&& cmd[i] == open_parenthes && escaped(cmd, i) == false)
			parenthes++;
		else if (opened_quote == false
			&& cmd[i] == close_parenthes && escaped(cmd, i) == false)
			parenthes--;
		i++;
	}
	return (parenthes != 0);
}

inline int	check_cmd_sequenses(char *cmd)
{
	if (escaped_eof(cmd) == escape)
	{
		ft_printf("%s\n", MSG_ERR_CMD_EEOF);
		return (false);
	}
	if (has_opened_quotes(cmd, 0, ft_strlen(cmd)))
	{
		ft_printf("%s, %c\n", MSG_ERR_CMD_UQ,
			has_opened_quotes(cmd, 0, ft_strlen(cmd)));
		return (false);
	}
	if (more_two_sequenses_controls(cmd, 0, 0, 0))
	{
		ft_printf("%s %c\n", MSG_ERR_MORE2CNTRLS,
			more_two_sequenses_controls(cmd, 0, 0, 0));
		return (false);
	}
	if (has_opened_parenthes(cmd, 0, 0, 0))
	{
		ft_printf("%s\n", MSG_ERR_CMD_HAS_UP);
		return (false);
	}
	return (true);
}
