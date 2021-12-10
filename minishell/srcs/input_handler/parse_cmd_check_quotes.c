/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_check_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:35:24 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/10 18:02:31 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline int	is_open_quotes(char *cmd, t_iter *iter)
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

inline void	check_quotes(char *cmd, t_iter *iter)
{
	char	*pchar;

	if (iter->i != iter->k)
		return ;
	pchar = NULL;
	if (is_open_quotes(cmd, iter))
	{
		iter->k = cmd + iter->i - cmd + 1;
		while (true)
		{
			pchar = ft_strchr(cmd + iter->k, cmd[iter->i]);
			if (pchar && *(pchar - 1) == escape)
				iter->k = pchar - cmd + 1;
			else if (pchar)
			{
				iter->k = pchar - cmd + 1;
				iter->in_qoutes = *pchar;
				return ;
			}
			else if (pchar == NULL)
				break ;
		}
	}
	iter->k = iter->i + 1;
	iter->in_qoutes = false;
}
