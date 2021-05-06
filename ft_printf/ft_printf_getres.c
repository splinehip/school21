/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getres.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:20:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/06 17:45:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getres(const char **ss, va_list ap)
{
	char	*res;
	char	*tmp;
	size_t	i;

	(void)ap;
	i = 0;
	res = NULL;
	while (ss[i] != NULL)
	{
		tmp = res;
		if (ss[i][0] == '%' && ss[i][1] == '%')
			res = ft_strjoin(res, ss[i] + 1);
		else
			res = ft_strjoin(res, ss[i]);
		if (tmp != NULL)
			free(tmp);
		i++;
	}
	return (res);
}
