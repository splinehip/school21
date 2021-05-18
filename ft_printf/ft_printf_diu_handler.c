/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:23:15 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/18 15:04:42 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_handler(char **ps, t_args *args, int precision)
{
	char	*s;
	char	*new_s;

	s = *ps;
	if ((*args).p >= 0 && ((size_t)(*args).p > ft_strlen(s)
		|| ((size_t)(*args).p == ft_strlen(s) && s[0] == '-')))
	{
		if (s[0] == '-')
			precision++;
		new_s = (char *)ft_calloc((size_t)precision + 1, sizeof(char));
		new_s = ft_memset(new_s, '0', (size_t)precision);
		if (new_s == NULL)
			*ps = NULL;
		if (new_s == NULL)
			return ;
		if (s[0] == '-')
			new_s[0] = '-';
		if (s[0] == '-')
			s[0] = '0';
		ft_memcpy(new_s + (precision - ft_strlen(s)), s, ft_strlen(s));
		*ps = new_s;
		free(s);
	}
	if ((*args).p == 0 && **ps == '0')
		**ps = 0;
}

static void	width_handler_fres_sing(char **pfres, char **ps, t_args *args)
{
	char	*s;
	char	*fres;

	fres = *pfres;
	s = *ps;
	if (s[0] == '-' && fres[0] == ' ')
		ft_memcpy(fres + (*args).w - ft_strlen(s), s, ft_strlen(s));
	else if (s[0] == '-' && fres[0] == '0')
	{
		s[0] = fres[0];
		fres[0] = '-';
		ft_memcpy(fres + (*args).w - ft_strlen(s), s, ft_strlen(s));
	}
	else if (fres[0] == '+' && fres[1] == ' ')
	{
		fres[0] = ' ';
		fres[(*args).w - ft_strlen(s) - 1] = '+';
		ft_memcpy(fres + (*args).w - ft_strlen(s), s, ft_strlen(s) + 1);
	}
	else if (fres[0] == '+' && fres[1] == '0')
		ft_memcpy(fres + (*args).w - ft_strlen(s), s, ft_strlen(s) + 1);
}

static void	width_handler(char **pfres, char **ps, t_args *args)
{
	char	*fres;
	char	*s;

	s = *ps;
	fres = *pfres;
	if ((*args).w >= 0 && (size_t)(*args).w > ft_strlen(s))
	{
		if ((s[0] == '-' || fres[0] == '+') && (*args).align_left == 0)
			width_handler_fres_sing(pfres, ps, args);
		else if ((*args).align_left)
			ft_memcpy(fres, s, ft_strlen(s));
		else
			ft_memcpy(fres + (*args).w - ft_strlen(s), s, ft_strlen(s));
		*pfres = ft_strdup(fres);
	}
	else if (fres[0] == '+')
		*pfres = ft_strjoin("+", s);
	else
		*pfres = ft_strdup(s);
	free(fres);
}

static void	get_res(char **pfres, char **ps, t_args *args)
{
	if (*pfres != NULL)
	{
		precision_handler(ps, args, (*args).p);
		if (*ps == NULL)
		{
			(*args).res = NULL;
			free(*pfres);
			return ;
		}
		width_handler(pfres, ps, args);
		if (*pfres == NULL)
		{
			(*args).res = NULL;
			free(*ps);
			return ;
		}
	}
	else
		*pfres = *ps;
	if (*pfres != *ps)
		free(*ps);
	(*args).len += ft_strlen(*pfres);
	ft_printf_update_args_res(args, *pfres, 3);
	free(*pfres);
}

void	ft_printf_diu_handler(t_args *args, const char *ssi, va_list ap)
{
	char	*s;
	char	*fres;

	s = NULL;
	fres = NULL;
	(*args).old_len = (*args).len;
	if (ft_strlen(ssi) != 2)
		fres = ft_printf_flag_handler(args, ssi, ap);
	if (ssi[ft_strlen(ssi) - 1] == 'u')
		s = ft_uitoa(va_arg(ap, unsigned int));
	else
		s = ft_itoa(va_arg(ap, int));
	if ((fres == NULL && ft_strlen(ssi) != 2) || s == NULL)
	{
		(*args).res = NULL;
		if (fres != NULL)
			free(fres);
		if (s != NULL)
			free(s);
		return ;
	}
	get_res(&fres, &s, args);
}
