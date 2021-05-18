/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aplay_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:57:28 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/17 22:07:11 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_aplay_handlers(t_args *args, const char *ssi, va_list ap)
{
	if (ssi[ft_strlen(ssi) - 1] == 'c')
		ft_printf_c_handler(args, ssi, ap);
	else if (ssi[ft_strlen(ssi) - 1] == 's')
		ft_printf_s_handler(args, ssi, ap);
	else if (ssi[ft_strlen(ssi) - 1] == 'd' || ssi[ft_strlen(ssi) - 1] == 'i')
		ft_printf_di_handler(args, ssi, ap);
	else if (ssi[ft_strlen(ssi) - 1] == 'p')
		ft_printf_p_handler(args, ssi, ap);
	else
		(*args).res = NULL;
}
