/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/21 16:21:57 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "error_msgs.h"
#include "builtins.h"
#include "input_handler.h"

inline char	*parse_cmd(char *cmd, char **env)
{
	int		checker_res;
	char	*res;

	res = NULL;
	checker_res = check_cmd_sequenses(cmd);
	if (checker_res == false)
		return (res);
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
