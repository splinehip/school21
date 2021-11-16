/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_update_args_res.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:31:12 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/24 12:24:21 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

inline void	ft_printf_update_args_res(t_args *args, const char *s, int code)
{
	(void)code;
	(*args).res = ft_memmove(
			(char *)ft_calloc((*args).len, sizeof(char)),
			(*args).res, (*args).old_len);
	ft_memmove((*args).res + (*args).old_len, s,
		(*args).len - (*args).old_len);
}
