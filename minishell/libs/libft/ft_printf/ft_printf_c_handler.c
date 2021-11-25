/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:08:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/24 12:25:01 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	update_res(t_args *args, char *fres, va_list ap)
{
	if ((*args).w != 0)
		(*args).len += ft_strlen(fres);
	else
		(*args).len += 1;
	if ((*args).align_left || (*args).w == 0)
		fres[0] = va_arg(ap, int);
	else
		fres[(*args).w - 1] = va_arg(ap, int);
	ft_printf_update_args_res(args, fres, 3);
}

void	ft_printf_c_handler(t_args *args, const char *ssi, va_list ap)
{
	char	*fres;

	(*args).old_len = (*args).len;
	if (ft_strlen(ssi) == 2)
	{
		fres = ft_strjoinchr(NULL, va_arg(ap, int));
		if (fres == NULL)
			(*args).res = NULL;
		if (fres == NULL)
			return ;
		(*args).len += 1;
		ft_printf_update_args_res(args, fres, 3);
		free(fres);
	}
	else
	{
		fres = ft_printf_flag_handler(args, ssi, ap);
		if (fres == NULL)
			(*args).res = NULL;
		if (fres == NULL)
			return ;
		update_res(args, fres, ap);
		free(fres);
	}
}
