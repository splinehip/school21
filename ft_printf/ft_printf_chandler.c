/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chandler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:08:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/07 14:48:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_chandler(char *res, const char *ssi, va_list ap)
{
	if (ft_strlen(ssi) == 2)
		res = ft_strjoinchr(res, va_arg(ap, int));
	return (res);
}
