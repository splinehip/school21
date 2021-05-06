/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getres.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:20:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/05 23:28:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getres(const char **ss, va_list ap)
{
	char	*tmp;
	char	*res;
	size_t	len;

	(void)ap;
	if (ss == NULL)
		return (NULL);
	res = NULL;
	len = 0;
	while (ss[len] != NULL)
	{
		ft_putnbr_fd(len, 1);
		ft_putendl_fd(ss[len++], 1);
	}
	len = 0;
	while (ss[len] != NULL)
	{
		tmp = res;
		res = ft_strjoin(res, ss[len]);
		len++;
		if (tmp != NULL)
			free(tmp);
	}
	return (res);
}
