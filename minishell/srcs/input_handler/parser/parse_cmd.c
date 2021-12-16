/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/16 15:26:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "input_handler.h"

inline char	has_opened_quots(char *cmd, int start, int end)
{
	char	*quote_type;

	quote_type = NULL;
	while (start <= end && cmd[start] != ends)
	{
		if (cmd[start] == quote || cmd[start] == single_quote)
		{
			if (quote_type == NULL)
				quote_type = &cmd[start];
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

static inline char	has_opened_quots_or_escaped_eof(char *cmd)
{
	if (escaped_eof(cmd))
		return (escape);
	return (has_opened_quots(cmd, 0, ft_strlen(cmd)));
}

inline char	*parse_cmd(char *cmd, char **env)
{
	char	checker_res;
	char	*res;

	res = NULL;
	checker_res = has_opened_quots_or_escaped_eof(cmd);
	if (checker_res)
	{
		if (checker_res == escape)
			ft_printf("%s\n", MSG_ERR_CMD_EEOF);
		if (checker_res == quote || checker_res == single_quote)
			ft_printf("%s, %c\n", MSG_ERR_CMD_UQ, checker_res);
		return (res);
	}
	if (ft_strchr(cmd, asterisk))
		res = do_parse_whith_asterisk(cmd, env);
	else
		res = do_parse(cmd, env);
	if (res == NULL)
	{
		ft_printf("Parse cmd error.\n");
		return (res);
	}
	ft_printf("EXPANDED CMD: >%s<\n", res);
	return (res);
}
