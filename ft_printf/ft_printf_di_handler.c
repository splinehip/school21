/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:40:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/11 15:40:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*s_res(char *res, char *s)
{
	if (s != NULL)
	{
		res = ft_strjoin(res, s);
	}
	else
		res = NULL;
	return (res);
}

static void	set_s_fres(int width, char **fres, char **s)
{
	if (ft_strlen(*fres) > (size_t)width && (*fres)[1] == ' ')
	{
		(*fres)[(size_t)width - ft_strlen(*s) - 1] = (*fres)[0];
		(*fres)[0] = (*fres)[1];
	}
	else if (*s[0] == '-' && (*fres)[0] == '0')
	{
		(*fres)[0] = (*s)[0];
		(*s)[0] = (*fres)[1];
	}
	(*fres)[(size_t)width - ft_strlen(*s)] = '\0';
}

static void	set_precision(char **fres, char **s, int precision)
{
	char	*tmp;
	char	*ps;

	ps = (char *)ft_calloc((size_t)precision - ft_strlen(*s) + 1, sizeof(char));
	ps = ft_memset(ps, '0', (size_t)precision - ft_strlen(*s));
	if (ps != NULL)
	{
		if ((*s)[0] == '-')
		{
			(*s)[0] = '0';
			tmp = ps;
			ps = ft_strjoin("-", ps);
			free(tmp);
		}
		tmp = *s;
		*s = ft_strjoin(ps, *s);
		free(tmp);
		if (ps != NULL)
			free(ps);
	}
	if (ps == NULL)
	{
		free(*fres);
		*fres = NULL;
	}
}

static void	s_fres(char **fres, char **s, int width, int precision)
{
	if (*fres != NULL && *s != NULL)
	{
		if (precision >=0 && (size_t)precision > ft_strlen(*s))
			set_precision(fres, s, precision);
		if (*fres != NULL)
		{
			if ((size_t)width > ft_strlen(*s))
				set_s_fres(width, fres, s);
			else if ((*fres)[0] == '+')
				(*fres)[1] = '\0';
			else
				(*fres)[0] = '\0';
		}
	}
	if (*fres == NULL || *s == NULL)
	{
		if (*fres != NULL)
		{
			free(*fres);
			*fres = NULL;
		}
		if (*s != NULL)
			free(*s);
	}
}

char	*ft_printf_di_handler(char *res, const char *ssi, va_list ap)
{
	char	*fres;
	char	*tmp;
	char	*s;
	int		width;
	int		precision;

	s = ft_itoa(va_arg(ap, int));
	if (ft_strlen(ssi) == 2)
		res = s_res(res, s);
	else
	{
		fres = ft_printf_flag_handler(ssi, &width, &precision, ap);
		s_fres(&fres, &s, width, precision);
		if (fres == NULL)
			return (NULL);
		tmp = fres;
		fres = ft_strjoin(fres, s);
		free(tmp);
		res = ft_strjoin(res, fres);
		free(fres);
	}
	if (s != NULL)
		free(s);
	return (res);
}
