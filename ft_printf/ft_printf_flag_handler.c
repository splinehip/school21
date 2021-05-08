/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 10:00:01 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/08 18:04:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_flag_handler(const char *ssi, va_list ap)
{
	int	width;
	int	precision;

	width = 0;
	precision = -1;
	ft_printf_wp_handler(ssi, &width, &precision, ap);
	ft_putstr_fd("\nWIDTH: ", 1);
	ft_putnbr_fd(width, 1);
	ft_putstr_fd("\nPRECISION: ", 1);
	ft_putnbr_fd(precision, 1);
	ft_putchar_fd('\n', 1);
	return (ft_strdup("STRDUP\n"));
}
