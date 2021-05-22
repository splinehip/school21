/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prc_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 08:14:21 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/22 09:42:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	get_res(char **pfres, const char *ssi, t_args *args)
{
	char	*fres;

	fres = *pfres;
	if ((*args).align_left && (size_t)(*args).w > 1)
		fres[0] = ssi[0];
	else if ((*args).w > 0)
		fres[(*args).w - 1] = ssi[0];
	else
	{
		(*args).len += 1;
		ft_printf_update_args_res(args, ssi, 0);
		return ;
	}
	(*args).len += ft_strlen(fres);
	ft_printf_update_args_res(args, fres, 3);
}

void	ft_printf_prc_handler(t_args *args, const char *ssi, va_list ap)
{
	char	*fres;

	(*args).old_len = (*args).len;
	if (ft_strlen(ssi) == 2 || MAC_OS == 0)
	{
		(*args).len += 1;
		ft_printf_update_args_res(args, ssi, 0);
	}
	else
	{
		fres = ft_printf_flag_handler(args, ssi, ap);
		if (fres == NULL)
		{
			(*args).res = NULL;
			return ;
		}
		get_res(&fres, ssi, args);
		free(fres);
	}
}
