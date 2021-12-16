/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_template.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:36:13 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/16 15:08:57 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline int	do_check_quotes_or_break(
	char *cmd, t_extract *args, int *i, char **quote_type)
{
	if ((cmd[*i] == quote || cmd[*i] == single_quote)
		&& escaped(cmd, *i) == false)
	{
		if (*quote_type && cmd[*i] == **quote_type)
			*quote_type = NULL;
		else if (*quote_type == NULL)
			*quote_type = cmd + *i;
		return (false);
	}
	if ((cmd[*i] == space && escaped(cmd, *i) == false
			&& *quote_type == NULL) || *i == args->prev_end)
	{
		if (*i == args->prev_end && cmd[*i] == space)
			*i += 1;
		return (true);
	}
	return (false);
}

static inline void	find_start(char *cmd, t_extract *args)
{
	char	opened_quote;
	char	*quote_type;

	quote_type = NULL;
	args->start = args->pchar - cmd;
	opened_quote = has_opened_quots(cmd, args->prev_end, args->start);
	if (opened_quote)
	{
		while (args->start >= args->prev_end)
		{
			if (cmd[args->start] == opened_quote
				&& escaped(cmd, args->start) == false)
				break ;
			args->start--;
		}
		return ;
	}
	while (args->start >= args->prev_end)
	{
		if (do_check_quotes_or_break(cmd, args, &args->start, &quote_type))
			break ;
		args->start--;
	}
}

static inline void	find_end(char *cmd, t_extract *args)
{
	char	opened_quote;
	char	*quote_type;

	quote_type = NULL;
	args->end = args->pchar - cmd;
	opened_quote = has_opened_quots(cmd, args->end, ft_strlen(cmd));
	if (opened_quote)
	{
		while (cmd[args->end] != ends)
		{
			if (cmd[args->end++] == opened_quote
				&& escaped(cmd, args->end) == false)
				break ;
		}
		return ;
	}
	while (cmd[args->end] != ends)
	{
		if (do_check_quotes_or_break(cmd, args, &args->end, &quote_type))
			break ;
		args->end++;
	}
}

inline void	get_template_border(char *cmd, t_extract *args)
{
	find_start(cmd, args);
	find_end(cmd, args);
}
