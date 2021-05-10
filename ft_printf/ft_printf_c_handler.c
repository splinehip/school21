/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:08:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/10 16:43:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_c_handler(char *res, const char *ssi, va_list ap)
{
	char	*fres;
	char	*tmp;
	int		width;
	int		precision;

	if (ft_strlen(ssi) == 2)
		res = ft_strjoinchr(res, va_arg(ap, int));
	else
	{
		fres = ft_printf_flag_handler(ssi, &width, &precision, ap);
		if (fres == NULL)
			return (NULL);
		if (width > 0)
			fres[width - 1] = '\0';
		tmp = fres;
		fres = ft_strjoinchr(fres, va_arg(ap, int));
		free(tmp);
		res = ft_strjoin(res, fres);
		if (fres != NULL)
			free(fres);
	}
	return (res);
}
