/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_is_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:24 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/09 16:21:25 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "input_handler.h"

inline int	is_quotes(char *cmd, t_iter *iter)
{
	if (cmd[iter->i] == quote || cmd[iter->i] == single_quote)
	{
		if (iter->i == 0)
			return (true);
		else if (cmd[iter->i - 1] != escape)
			return (true);
	}
	return (false);
}
