/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:14:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/10 12:49:09 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_printf_isconvsymbol(unsigned char c);
char	*ft_printf_getres(const char **ss, char *res, va_list ap);
char	*ft_printf_getconversion(char *res, const char *ssi, va_list ap);
void	ft_printf_wp_handler(const char *ssi, int *w, int *p, va_list ap);
char	*ft_printf_flag_handler(const char *ssi, int *w, int *p, va_list ap);
char	*ft_printf_c_handler(char *res, const char *ssi, va_list ap);
#endif
