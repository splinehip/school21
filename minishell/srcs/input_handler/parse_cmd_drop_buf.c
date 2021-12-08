/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_drop_buf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:33:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/08 17:11:13 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

inline int	drop_buf(char *cmd, t_iter *iter)
{
	char	*tmp;

	if (cmd[iter->i] == ends && iter->buf[iter->j - 1] == space)
		iter->buf[iter->j - 1] = ends;
	tmp = iter->res;
	iter->res = ft_strjoin(iter->res, iter->buf);
	free(tmp);
	iter->j = 0;
	if (iter->res == NULL)
		return (unsucsses);
	return (sucsses);
}
