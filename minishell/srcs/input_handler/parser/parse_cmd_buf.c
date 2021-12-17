/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:33:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/17 20:44:41 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

static inline int	do_drop(char **res, char *buf, int *j)
{
	char	*tmp;

	tmp = *res;
	*res = ft_strjoin(*res, buf);
	free(tmp);
	*j = 0;
	buf[0] = 0;
	if (*res == NULL)
		return (unsucsses);
	return (sucsses);
}

static inline int	do_update(char **res, char *str, char *buf, int *j)
{
	int	i;

	if (str == NULL)
		return (unsucsses);
	if (*j == BUF_SIZE)
		if (do_drop(res, buf, j) == unsucsses)
			return (unsucsses);
	i = 0;
	while (str[i])
	{
		buf[*j] = str[i++];
		*j += 1;
		buf[*j] = 0;
		if (*j == BUF_SIZE)
			if (do_drop(res, buf, j) == unsucsses)
				return (unsucsses);
	}
	return (sucsses);
}

inline int	do_update_buf(char *str, void *pargs, int type_args, int drop_buf)
{
	t_iter		*iter;
	t_extract	*extract;

	if (type_args == piter)
	{
		iter = (t_iter *)pargs;
		if (drop_buf)
			return (do_drop(&iter->res, &iter->buf[0], &iter->j));
		return (do_update(&iter->res, str, &iter->buf[0], &iter->j));
	}
	else if (type_args == pextract)
	{
		extract = (t_extract *)pargs;
		if (drop_buf)
			return (do_drop(&extract->res, &extract->buf[0], &extract->j));
		return (do_update(&extract->res, str, &extract->buf[0], &extract->j));
	}
	return (sucsses);
}
