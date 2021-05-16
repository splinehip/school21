/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 10:00:01 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/15 22:06:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hasflag(const char *ssi, int c)
{
	if (ft_strchr(ssi, c) != NULL)
		if (ft_strchr("%-+ #0", *(ft_strchr(ssi, c) - 1)) != NULL)
			return (1);
	return (0);
}

static int	needzero(const char *ssi)
{
	if (ft_strchr("diouxXaAeEfFgG", ssi[ft_strlen(ssi) - 1]) != NULL)
	{
		if (ft_strchr("diouxX", ssi[ft_strlen(ssi) - 1]) != NULL)
		{
			if (ft_strchr(ssi, '.') != NULL)
				return (0);
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

static char	*to_fild(char *flag, char *res)
{
	char	*tmp;

	tmp = res;
	res = ft_strjoin(flag, res);
	if (tmp != NULL)
		free(tmp);
	return (res);
}

static int	isdi(const char *ssi)
{
	if (ssi[ft_strlen(ssi) - 1] == 'd' || ssi[ft_strlen(ssi) - 1] == 'i')
		return (1);
	return (0);
}

char	*ft_printf_flag_handler(t_args *args, const char *ssi, va_list ap)
{
	char	*res;

	ft_printf_wp_handler(args, ssi, ap);
	if (hasflag(ssi, '-'))
		(*args).align_left = 1;
	res = (char *)ft_calloc((*args).w + 1, sizeof(char));
	res = ft_memset(res, ' ', (*args).w);
	if (res == NULL)
		return (NULL);
	if (hasflag(ssi, '0') && (*args).align_left == 0 && needzero(ssi))
		res = ft_memset(res, '0', (*args).w);
	if (hasflag(ssi, '+') && isdi(ssi))
		res = to_fild("+", res);
	else if (hasflag(ssi, ' ') && isdi(ssi))
		res = to_fild(" ", res);
	if (hasflag(ssi, '#') && ssi[ft_strlen(ssi) - 1] == 'x')
		res = to_fild("0x", res);
	if (hasflag(ssi, '#') && ssi[ft_strlen(ssi) - 1] == 'X')
		res = to_fild("0X", res);
	return (res);
}
