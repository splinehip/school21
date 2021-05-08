/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wp_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:06:18 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/08 19:18:41 by cflorind         ###   ########.fr       */
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

static void	get_wp_from_str(const char *ssi, int *w, int *p)
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
			*w = get_wp_int(ssi, s1, s2);
			s1 = s2;
		}
		if (*s1 == '.' && s1[1] != '*')
		{
			s2 = ++s1;
			while ((*s2 >= '0' && *s2 <= '9') && *s2 != 0)
				s2++;
			*p = get_wp_int(ssi, s1, s2);
		}
	}
}

void	ft_printf_wp_handler(const char *ssi, int *w, int *p, va_list ap)
{
	const char	*s1;
	const char	*s2;

	s1 = ft_strchr(ssi, '*');
	if (s1 != NULL)
	{
		s2 = ft_strchr(s1 + 1, '*');
		if (s2 != NULL)
		{
			*w = va_arg(ap, int);
			*p = va_arg(ap, int);
		}
		else if (s1[-1] == '.')
			*p = va_arg(ap, int);
		else
			*w = va_arg(ap, int);
	}
	get_wp_from_str(ssi, w, p);
}
