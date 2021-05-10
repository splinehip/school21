/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getres.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:20:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/10 17:12:07 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getres(const char **ss, char *res, va_list ap)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (ss[i] != NULL)
	{
		tmp = res;
		if (ss[i][0] == '%' && ss[i][1] == '%')
			res = ft_strjoin(res, ss[i] + 1);
		else if (ss[i][0] == '%')
			res = ft_printf_getconversion(res, ss[i], ap);
		else
			res = ft_strjoin(res, ss[i]);
		if (tmp != NULL)
			free(tmp);
		if (res == NULL)
			return (NULL);
		i++;
	}
	return (res);
}
