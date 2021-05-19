/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:46:19 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/19 14:39:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_args	args;

	if (s == NULL)
		return (-1);
	if (ft_strlen(s) == 0)
		return (0);
	args.len = 0;
	args.res = NULL;
	va_start(ap, s);
	ft_printf_get_conversions(s, &args, ap);
	va_end(ap);
	if (args.res == NULL)
		return (-1);
	(void)(write(1, args.res, args.len) + 1);
	free(args.res);
	return (args.len);
}
