/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:50:13 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/11 12:28:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	s_fres(char *fres, char *s, int width, int precision)
{
	if (fres != NULL && s != NULL)
	{
		if (precision >= 0 && (size_t)precision < ft_strlen(s))
			s[precision] = '\0';
		if ((size_t)width > ft_strlen(s))
			fres[(size_t)width - ft_strlen(s)] = '\0';
	}
	else
	{
		if (fres != NULL)
			free(fres);
		fres = NULL;
		if (s != NULL)
			free(s);
	}
}

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
		s = ft_strdup(va_arg(ap, char *));
		s_fres(fres, s, width, precision);
		if (fres == NULL)
			return (NULL);
		tmp = fres;
		fres = ft_strjoin(fres, s);
		free(tmp);
		free(s);
		if (fres == NULL)
			return (NULL);
		res = ft_strjoin(res, fres);
		free(fres);
	}
	return (res);
}
