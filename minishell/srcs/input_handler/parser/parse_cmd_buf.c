/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:33:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/18 12:35:27 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

inline int	do_drop_buf(char **res, char *buf, int *j)
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

inline int	do_update_buf(char **res, char *str, char *buf, int *j)
{
	int	i;

	if (str == NULL)
		return (unsucsses);
	if (*j == BUF_SIZE)
		if (do_drop_buf(res, buf, j) == unsucsses)
			return (unsucsses);
	i = 0;
	while (str[i])
	{
		buf[(*j)++] = str[i++];
		buf[*j] = 0;
		if (*j == BUF_SIZE)
			if (do_drop_buf(res, buf, j) == unsucsses)
				return (unsucsses);
	}
	return (sucsses);
}
