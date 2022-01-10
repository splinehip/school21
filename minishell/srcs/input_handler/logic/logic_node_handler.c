/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_node_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:54:43 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/10 21:22:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "error_msgs.h"
#include "bool.h"
#include "input_handler.h"
#include "libft.h"
#include "minishell.h"

static char	*extract_first(char *str, size_t n)
{
	char	*tmp;
	char	*new;

	tmp = malloc(n);
	if (!tmp)
		return (NULL);
	tmp = ft_memcpy(tmp, str, n - 1);
	tmp[n - 1] = 0;
	new = trim_and_update_cmdstr(&tmp);
	return (new);
}

static char	*extract_second(char *str, size_t n)
{
	char	*tmp;
	char	*new;
	size_t	len;

	len = ft_strlen(str) - n;
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, &str[n], len);
	tmp[len] = 0;
	new = trim_and_update_cmdstr(&tmp);
	return (new);
}

static size_t	split_symbol(char *cmd, char opened_quote,
		char opened_par, size_t i)
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
		if ((cmd[i] == open_parenth || cmd[i] == close_parenth)
			&& opened_quote == 0)
		{
			if (cmd[i] == open_parenth)
				opened_par += 1;
			else if (cmd[i] == close_parenth)
				opened_par -= 1;
		}
		if ((cmd[i] == and || cmd[i] == or)
			&& opened_quote == 0 && opened_par == 0)
			if (cmd[i + 1] == cmd[i])
				return (i);
		i++;
	}
	return (0);
}

t_node	*extract_node(char **str)
{
	t_node	*node;
	size_t	n;

	node = malloc(sizeof(t_node));
	if (node == NULL)
	{
		print_err(MSG_ERR_MEM, NULL, 0);
		return (NULL);
	}
	node->type = has_logical_operators(*str, 0, 0, 0);
	n = split_symbol(*str, 0, 0, 0);
	if (!n)
	{
		print_err(MSG_ERR_SYNATX, NULL, 0);
		free (node);
		return (NULL);
	}
	node->left = extract_first(*str, n);
	node->right = extract_second(*str, n + 2);
	return (node);
}

int	exec_node(t_node *node, char ***env)
{
	int	res;

	if (node == NULL)
		return (-1);
	res = input_handler(&node->left, env);
	if (res == -1 || (node->type == and && res != 0)
		|| (node->type == or && res == 0))
		return (res);
	return (input_handler(&node->right, env));
}
