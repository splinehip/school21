/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/14 13:44:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "error_msgs.h"
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
