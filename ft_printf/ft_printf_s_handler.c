/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:50:13 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/10 17:07:14 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_s_handler(char *res, const char *ssi, va_list ap)
{
	char	*fres;
	char	*s;
	char	*tmp;
	int		width;
	int		precision;

	if (ft_strlen(ssi) == 2)
		res = ft_strjoin(res, va_arg(ap, char *));
	else
	{
		fres = ft_printf_flag_handler(ssi, &width, &precision, ap);
		if (fres == NULL)
			return (NULL);
		s = va_arg(ap, char *);
		if ((size_t)width > ft_strlen(s))
			fres[(size_t)width - ft_strlen(s)] = '\0';
		tmp = fres;
		fres = ft_strjoin(fres, s);
		free(tmp);
		res = ft_strjoin(res, fres);
		if (fres != NULL)
			free(fres);
	}
	return (res);
}
