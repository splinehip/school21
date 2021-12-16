/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/16 10:52:38 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "input_handler.h"

static inline char	has_opened_quots_or_escaped_eof(
	char *cmd, int i, int quot_count, char quot_type)
{
	if (cmd[ft_strlen(cmd) - 1] == escape
		&& escaped(cmd, ft_strlen(cmd) - 1) == false)
		return (escape);
	while (cmd[i] != ends)
	{
		if ((cmd[i] == quote || cmd[i] == single_quote)
			&& escaped(cmd, i) == false)
		{
			if (quot_type == 0)
				quot_type = cmd[i];
			if (cmd[i] == quot_type)
				quot_count++;
			if (quot_count % 2 == 0)
				quot_type = 0;
		}
		i++;
	}
	if (quot_count && quot_count % 2 != 0)
		return (quot_type);
	return (false);
}

inline char	*parse_cmd(char *cmd, char **env)
{
	char	checker_res;
	char	*res;

	res = NULL;
	checker_res = has_opened_quots_or_escaped_eof(cmd, 0, 0, 0);
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
