/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 10:00:01 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/10 16:35:49 by cflorind         ###   ########.fr       */
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

char	*ft_printf_flag_handler(const char *ssi, int *w, int *p, va_list ap)
{
	char	*res;

	*w = 0;
	*p = -1;
	ft_printf_wp_handler(ssi, w, p, ap);
	res = (char *)ft_calloc(*w + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	res = ft_memset(res, ' ', *w);
	if (hasflag(ssi, '0') && needzero(ssi))
		res = ft_memset(res, '0', *w);
	if (hasflag(ssi, '-'))
		res[0] = '\0';
	if ((hasflag(ssi, ' ') || hasflag(ssi, '+')) && isdi(ssi))
	{
		if (hasflag(ssi, '+'))
			res = to_fild("+", res);
		else
			res = to_fild(" ", res);
	}
	if (res != NULL && hasflag(ssi, '#') && ssi[ft_strlen(ssi) - 1] == 'x')
		res = to_fild("0x", res);
	if (res != NULL && hasflag(ssi, '#') && ssi[ft_strlen(ssi) - 1] == 'X')
		res = to_fild("0X", res);
	return (res);
}
