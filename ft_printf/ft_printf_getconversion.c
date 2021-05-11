/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getconversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:57:28 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/10 21:40:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getconversion(char *res, const char *ssi, va_list ap)
{
	if (ssi[ft_strlen(ssi) - 1] == 'c')
		res = ft_printf_c_handler(res, ssi, ap);
	if (ssi[ft_strlen(ssi) - 1] == 's')
		res = ft_printf_s_handler(res, ssi, ap);
	if (ssi[ft_strlen(ssi) - 1] == 'd' || ssi[ft_strlen(ssi) - 1] == 'i')
		res = ft_printf_di_handler(res, ssi, ap);
	return (res);
}
