/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:08:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/08 17:13:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_c_handler(char *res, const char *ssi, va_list ap)
{
	char	*fres;

	if (ft_strlen(ssi) == 2)
		res = ft_strjoinchr(res, va_arg(ap, int));
	else
	{
		fres = ft_printf_flag_handler(ssi, ap);
		res = ft_strjoin(fres, res);
		free(fres);
	}
	return (res);
}
