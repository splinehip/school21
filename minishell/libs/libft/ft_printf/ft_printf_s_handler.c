/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:50:13 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/24 12:24:28 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*set_fres(char *fres, char *s, t_args *args)
{
	char	*res;

	res = NULL;
	if (fres == NULL || s == NULL)
		return (NULL);
	if (ft_strncmp(s, "(null)", 6) == 0 && MAC_OS == 0
		&& (*args).p >= 0 && (*args).p < 6)
		s[0] = '\0';
	if ((*args).p >= 0 && (size_t)(*args).p < ft_strlen(s))
		s[(*args).p] = '\0';
	if ((*args).align_left && (size_t)(*args).w > ft_strlen(s))
	{
		fres += ft_strlen(s);
		res = ft_strjoin(s, fres);
	}
	else if ((*args).w > 0 && (size_t)(*args).w > ft_strlen(s))
	{
		fres[(size_t)(*args).w - ft_strlen(s)] = '\0';
		res = ft_strjoin(fres, s);
	}
	else
		res = ft_strdup(s);
	return (res);
}

static void	get_res(t_args *args, const char *ssi, va_list ap)
{
	char	*fres;
	char	*s;
	char	*tmp_fres;
	char	*tmp_s;

	fres = ft_printf_flag_handler(args, ssi, ap);
	s = ft_strdup(va_arg(ap, char *));
	if (s == NULL)
		s = ft_strdup("(null)");
	tmp_fres = fres;
	tmp_s = s;
	fres = set_fres(fres, s, args);
	if (tmp_fres != NULL)
		free(tmp_fres);
	if (tmp_s != NULL)
		free(tmp_s);
	if (fres == NULL)
	{
		(*args).res = NULL;
		return ;
	}
	(*args).len += ft_strlen(fres);
	ft_printf_update_args_res(args, fres, 3);
	free(fres);
}

void	ft_printf_s_handler(t_args *args, const char *ssi, va_list ap)
{
	char	*s;

	(*args).old_len = (*args).len;
	if (ft_strlen(ssi) == 2)
	{
		s = va_arg(ap, char *);
		if (s == NULL)
			s = "(null)";
		(*args).len += ft_strlen(s);
		ft_printf_update_args_res(args, s, 3);
	}
	else
		get_res(args, ssi, ap);
}
