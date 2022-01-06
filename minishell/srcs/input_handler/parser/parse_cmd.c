/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/06 12:27:34 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "input_handler.h"
#include "minishell.h"

inline char	*parse_cmd(char *cmd, char **env, int type)
{
	char	*res;

	res = NULL;
	if (type == asterisk)
		res = do_parse_whith_asterisk(cmd, env);
	else
		res = do_parse(cmd, env);
	if (res == NULL)
		print_err(MSG_ERR_CMD_PARSEERR, NULL, 0);
	return (res);
}
