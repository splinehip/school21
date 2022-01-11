/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_has_opened_quotes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:11:37 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/11 14:12:33 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bool.h"
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
