/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:28:00 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/18 12:29:14 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_s(va_list ap)
{
	char	*res;
	char	*tmp;

	res = NULL;
	tmp = NULL;
	res = ft_tobase(10, 16, va_arg(ap, t_ulli));
	if (res == NULL)
		return (res);
	tmp = res;
	if (ft_strncmp(res, "0", 1) == 0)
		res = ft_strdup("(nil)");
	else
		res = ft_strjoin("0x", res);
	if (tmp != NULL)
		free(tmp);
	return (res);
}

static void	get_fres(char **pfres, char **ps, t_args *args)
{
	char	*fres;
	char	*s;

	s = *ps;
	fres = *pfres;
	if ((*args).align_left && (size_t)(*args).w > ft_strlen(s))
		ft_memcpy(fres, s, ft_strlen(s));
	else if ((size_t)(*args).w > ft_strlen(s))
		ft_memcpy(fres + ((*args).w - ft_strlen(s)), s, ft_strlen(s));
	else
	{
		*pfres = ft_strdup(s);
		free(fres);
	}
}

static void	get_res(char **pfres, char **ps, t_args *args)
{
	if (*ps == NULL)
	{
		(*args).res = NULL;
		if (*pfres != NULL)
			free(*pfres);
		return ;
	}
	get_fres(pfres, ps, args);
	if (*pfres == NULL)
	{
		(*args).res = NULL;
		return ;
	}
	ft_strtolower(pfres);
	(*args).len += ft_strlen(*pfres);
	ft_printf_update_args_res(args, *pfres, 3);
	free(*pfres);
	free(*ps);
}

void	ft_printf_p_handler(t_args *args, const char *ssi, va_list ap)
{
	char	*s;
	char	*fres;

	s = NULL;
	fres = NULL;
	(*args).old_len = (*args).len;
	if (ft_strlen(ssi) == 2)
	{
		s = get_s(ap);
		if (s == NULL)
			(*args).res = NULL;
		if (s == NULL)
			return ;
		ft_strtolower(&s);
		(*args).len += ft_strlen(s);
		ft_printf_update_args_res(args, s, 3);
		free(s);
	}
	else
	{
		fres = ft_printf_flag_handler(args, ssi, ap);
		if (fres != NULL)
			s = get_s(ap);
		get_res(&fres, &s, args);
	}
}
