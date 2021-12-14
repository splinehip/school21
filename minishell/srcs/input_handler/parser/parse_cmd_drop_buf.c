/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_drop_buf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:33:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/14 11:50:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

inline int	do_drop_buf(t_iter *iter)
{
	char	*tmp;

	tmp = iter->res;
	iter->res = ft_strjoin(iter->res, iter->buf);
	free(tmp);
	iter->j = 0;
	if (iter->res == NULL)
		return (unsucsses);
	return (sucsses);
}
