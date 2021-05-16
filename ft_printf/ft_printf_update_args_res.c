/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_update_args_res.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:31:12 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/16 18:48:01 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_update_args_res(t_args *args, const char *s, int code)
{
	if (code == 0)
	{
		(*args).res = ft_memmove(
				(char *)ft_calloc((*args).len + 1, sizeof(char)),
				(*args).res, (*args).len);
		ft_memmove((*args).res + (*args).len, s, 1);
		(*args).len += 1;
	}
	else if (code == 1)
	{
		(*args).res = ft_memmove((char *)ft_calloc((*args).len + ft_strlen(s),
					sizeof(char)), (*args).res, (*args).len);
		ft_memmove((*args).res + (*args).len, s, ft_strlen(s));
		(*args).len += ft_strlen(s);
	}
	else if (code == 3)
	{
		(*args).res = ft_memmove(
				(char *)ft_calloc((*args).len, sizeof(char)),
				(*args).res, (*args).old_len);
		ft_memmove((*args).res + (*args).old_len, s,
			(*args).len - (*args).old_len);
	}
}
