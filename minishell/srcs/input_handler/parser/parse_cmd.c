/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/29 15:05:34 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "input_handler.h"

inline char	*parse_cmd(char *cmd, char **env, int type)
{
	char	*res;

	res = NULL;
	if (type == asterisk)
		res = do_parse_whith_asterisk(cmd, env);
	else
		res = do_parse(cmd, env);
	if (res == NULL)
		printf(MSG_ERR_CMD_PARSEERR);
	return (res);
}
