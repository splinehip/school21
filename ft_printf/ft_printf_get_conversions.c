/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_conversions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:20:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/19 09:27:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isconvsymbol(unsigned char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static void	get_substr(const char *s, char **substr, size_t *i, size_t *pstart)
{
	while (1)
	{
		if (s[*i + 1] == 0)
		{
			*substr = ft_substr(s, *pstart, *i - *pstart + 1);
			break ;
		}
		else if (s[*i] == '%' && s[*pstart] != '%')
		{
			*substr = ft_substr(s, *pstart, *i - *pstart);
			*pstart = *i;
			*i -= 1;
			break ;
		}
		else if (isconvsymbol(s[*i]) && s[*pstart] == '%')
		{
			*i += 1;
			while (!isconvsymbol(s[*i]) && s[*i] != 0)
				*i += 1;
			*substr = ft_substr(s, *pstart, *i - *pstart + 1);
			*pstart = *i + 1;
			break ;
		}
		*i += 1;
	}
}

static void	apply_handlers(const char *substr, t_args *args, va_list ap)
{
	char	*args_res;

	args_res = (*args).res;
	if (substr[0] == '%' && substr[1] == '%')
		ft_printf_update_args_res(args, substr, 0);
	else if (substr[0] == '%')
		ft_printf_apply_handlers(args, substr, ap);
	else
		ft_printf_update_args_res(args, substr, 1);
	if (args_res != NULL)
		free(args_res);
}

void	ft_printf_get_conversions(const char *s, t_args *args, va_list ap)
{
	size_t	i;
	size_t	start;
	char	*substr;

	substr = NULL;
	i = 0;
	start = 0;
	while (s[i] != 0)
	{
		get_substr(s, &substr, &i, &start);
		if (substr == NULL)
		{
			if ((*args).res != NULL)
				free((*args).res);
			(*args).res = NULL;
			break ;
		}
		apply_handlers((const char *)substr, args, ap);
		free(substr);
		substr = NULL;
		if ((*args).res == NULL)
			break ;
		i++;
	}
}
