/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:47:20 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/22 09:58:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_handler(char **ps, t_args *args, int precision)
{
	char	*s;
	char	*new_s;

	s = *ps;
	if ((*args).p > 0 && (size_t)(*args).p > ft_strlen(s))
	{
		new_s = (char *)ft_calloc((size_t)precision + 1, sizeof(char));
		new_s = ft_memset(new_s, '0', (size_t)precision);
		if (new_s == NULL)
		{
			*ps = NULL;
			free(s);
			return ;
		}
		ft_memcpy(new_s + (precision - ft_strlen(s)), s, ft_strlen(s));
		*ps = new_s;
		free(s);
	}
	if ((*args).p == 0 && **ps == '0')
		**ps = 0;
}

static void	width_handler_fres_prefix(char **pfres, char **ps, t_args *args)
{
	char	*s;
	char	*fres;
	char	fres_fill;

	fres = *pfres;
	s = *ps;
	fres_fill = fres[2];
	ft_memcpy(fres + (*args).w - ft_strlen(s), s, ft_strlen(s));
	fres[(*args).w - ft_strlen(s) - 1] = fres[1];
	fres[(*args).w - ft_strlen(s) - 2] = fres[0];
	fres[0] = fres_fill;
	fres[1] = fres_fill;
}

static void	width_handler(char **pfres, char **ps, t_args *args)
{
	char	*fres;
	char	*s;

	s = *ps;
	fres = *pfres;
	if ((*args).w > 0 && (size_t)(*args).w > ft_strlen(s))
	{
		if ((fres[1] == 'x' || fres[1] == 'X') && (*args).align_left == 0)
			width_handler_fres_prefix(pfres, ps, args);
		else if ((*args).align_left && (fres[1] == 'x' || fres[1] == 'X'))
			ft_memcpy(fres + 2, s, ft_strlen(s));
		else if ((*args).align_left)
			ft_memcpy(fres, s, ft_strlen(s));
		else
			ft_memcpy(fres + (*args).w - ft_strlen(s), s, ft_strlen(s));
		*pfres = ft_strdup(fres);
	}
	else if (ft_strlen(fres) > 0 && (fres[1] == 'x' || fres[1] == 'X'))
	{
		fres[2] = 0;
		*pfres = ft_strjoin(fres, s);
	}
	else
		*pfres = *ps;
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

void	ft_printf_xX_handler(t_args *args, const char *ssi, va_list ap)
{
	char	*s;
	char	*fres;

	s = NULL;
	fres = NULL;
	(*args).old_len = (*args).len;
	if (ft_strlen(ssi) != 2)
		fres = ft_printf_flag_handler(args, ssi, ap);
	s = ft_tobase(10, 16, va_arg(ap, unsigned int));
	if ((fres == NULL && ft_strlen(ssi) != 2) || s == NULL)
	{
		(*args).res = NULL;
		if (fres != NULL)
			free(fres);
		if (s != NULL)
			free(s);
		return ;
	}
	if (ssi[ft_strlen(ssi) - 1] == 'x')
		ft_strtolower(&s);
	get_res(&fres, &s, args);
}
