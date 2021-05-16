/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wp_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:06:18 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/15 20:54:09 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_wp_int(const char *ssi, const char *s1, const char *s2)
{
	int		res;
	char	*tmp;

	tmp = ft_substr(ssi, (s1 - ssi) / sizeof(char), (s2 - s1) / sizeof(char));
	if (tmp == NULL)
		return (0);
	res = ft_atoi(tmp);
	free(tmp);
	return (res);
}

static void	get_wp_from_str(t_args *args, const char *ssi)
{
	const char	*s1;
	const char	*s2;

	s1 = ssi;
	while ((*s1 < '1' || *s1 > '9') && *s1 != '.' && *s1 != 0)
		s1++;
	if (*s1 != 0)
	{
		if ((*s1 >= '1' && *s1 <= '9'))
		{
			s2 = s1;
			while ((*s2 >= '0' && *s2 <= '9') && (*s2 != '.' && *s2 != 0))
				s2++;
			(*args).w = get_wp_int(ssi, s1, s2);
			s1 = s2;
		}
		if (*s1 == '.' && s1[1] != '*')
		{
			s2 = ++s1;
			while ((*s2 >= '0' && *s2 <= '9') && *s2 != 0)
				s2++;
			(*args).p = get_wp_int(ssi, s1, s2);
		}
	}
}

void	ft_printf_wp_handler(t_args *args, const char *ssi, va_list ap)
{
	const char	*s1;
	const char	*s2;

	(*args).w = 0;
	(*args).p = -1;
	(*args).align_left = 0;
	s1 = ft_strchr(ssi, '*');
	if (s1 != NULL)
	{
		s2 = ft_strchr(s1 + 1, '*');
		if (s2 != NULL)
		{
			(*args).w = va_arg(ap, int);
			(*args).p = va_arg(ap, int);
		}
		else if (s1[-1] == '.')
			(*args).p = va_arg(ap, int);
		else
			(*args).w = va_arg(ap, int);
	}
	get_wp_from_str(args, ssi);
	if ((*args).w < 0)
		(*args).align_left = 1;
	if ((*args).w < 0)
		(*args).w *= -1;
}
