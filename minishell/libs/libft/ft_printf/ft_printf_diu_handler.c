/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:23:15 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/24 12:24:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	precision_handler(char **ps, t_args *args, int precision)
{
	char	*s;

	s = *ps;
	if ((*args).p > 0 && ((size_t)(*args).p > ft_strlen(s)
		|| ((size_t)(*args).p == ft_strlen(s) && s[0] == '-')))
	{
		if (s[0] == '-')
			precision++;
		*ps = (char *)ft_calloc((size_t)precision + 1, sizeof(char));
		*ps = ft_memset(*ps, '0', (size_t)precision);
		if (*ps == NULL)
		{
			free(s);
			return ;
		}
		if (s[0] == '-')
			*ps[0] = '-';
		if (s[0] == '-')
			s[0] = '0';
		ft_memcpy(*ps + (precision - ft_strlen(s)), s, ft_strlen(s));
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
	if ((*args).w > 0 && (size_t)(*args).w > ft_strlen(s))
	{
		if ((s[0] == '-' || fres[0] == '+') && (*args).align_left == 0)
			width_handler_fres_sing(pfres, ps, args);
		else if (fres[0] == '+' && (*args).align_left)
			ft_memcpy(fres + 1, s, ft_strlen(s));
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
