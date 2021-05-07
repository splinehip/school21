/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getconversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:57:28 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/07 15:18:29 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getconversion(char *res, const char *ssi, va_list ap)
{
	if (ssi[ft_strlen(ssi) - 1] == 'c')
		res = ft_printf_chandler(res, ssi, ap);
	return (res);
}
