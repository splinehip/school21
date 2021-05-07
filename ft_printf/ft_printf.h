/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:14:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/07 15:15:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *s, ...);
char	*ft_printf_getres(const char **ss, char *res, va_list ap);
char	*ft_printf_getconversion(char *res, const char *ssi, va_list ap);
char	*ft_printf_chandler(char *res, const char *ssi, va_list ap);
#endif
