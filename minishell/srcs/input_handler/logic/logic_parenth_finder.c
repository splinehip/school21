/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_parenth_finder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:53:21 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/27 15:23:22 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "bool.h"
#include "input_handler.h"

inline size_t	find_paired_parenth(
		char *str, size_t start, char opened_quote, int opened_par)
{
	while (str[start] != ends)
	{
		if ((str[start] == quote || str[start] == single_quote)
			&& escaped(str, start) == false)
		{
			if (!opened_quote)
				opened_quote = str[start];
			else if (opened_quote == str[start])
				opened_quote = 0;
		}
		if ((str[start] == open_parenth || str[start] == close_parenth)
			&& opened_quote == 0)
		{
			if (str[start] == open_parenth)
				opened_par += 1;
			else if (!opened_par && str[start] == close_parenth)
				return (start);
			else
				opened_par -= 1;
		}
		start++;
	}
	return (0);
}

inline int	has_logical_operators(
		char *cmd, char opened_quote, char opened_par, size_t i)
{
	while (cmd[i] != ends)
	{
		if ((cmd[i] == quote || cmd[i] == single_quote)
			&& escaped(cmd, i) == false)
		{
			if (!opened_quote)
				opened_quote = cmd[i];
			else if (opened_quote == cmd[i])
				opened_quote = 0;
		}
		if (opened_par != -1 && opened_quote == 0
			&& (cmd[i] == open_parenth || cmd[i] == close_parenth))
		{
			if (cmd[i] == open_parenth)
				opened_par += 1;
			else if (cmd[i] == close_parenth)
				opened_par -= 1;
		}
		if ((cmd[i] == ampersand || cmd[i] == pipes)
			&& opened_quote == 0 && (opened_par == 0 || opened_par == -1))
			if (cmd[i + 1] == cmd[i])
				return (cmd[i]);
		i++;
	}
	return (0);
}
