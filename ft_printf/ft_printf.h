/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:14:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/16 18:48:07 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_args
{
	int			p;
	long int	w;
	char		*res;
	size_t		len;
	size_t		old_len;
	size_t		align_left;
}				t_args;

int		ft_printf(const char *s, ...);
void	ft_printf_get_conversions(const char *s, t_args *args, va_list ap);
void	ft_printf_update_args_res(t_args *args, const char *s, int code);
void	ft_printf_aplay_handlers(t_args *args, const char *ssi, va_list ap);
void	ft_printf_wp_handler(t_args *args, const char *ssi, va_list ap);
char	*ft_printf_flag_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_c_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_s_handler(t_args *args, const char *ssi, va_list ap);
void	ft_printf_di_handler(t_args *args, const char *ssi, va_list ap);

#endif
