/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:50:22 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/21 13:34:51 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_substr(const char *s, const char *ss)
{
	const char	*s_tmp;

	s_tmp = s;
	while (*ss != '\0')
	{
		if (*s_tmp == '\0')
			return (0);
		if (*s_tmp++ != *ss++)
		{
			return (0);
		}
	}
	return (1);
}

/*
Аргументы:

str – указатель на строку, в которой ведется поиск.
substr – указатель на искомую строку.

Возвращаемое значение:
NULL – если строка substr не входит в строку str. Указатель на первое вхождение
строки substr в строку str.

Описание:
Функция strnstr ищет первое вхождение строки (за исключением признак конца
строки), на которую указывает аргумент substr, в строку , на которую указывает
аргумент str. Если строка substr имеет нулевую длину, то функция вернет
указатель на начало строки str.
*/
char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	const char	*res;
	const char	*s;
	const char	*ss;

	s = str;
	ss = substr;
	if (!ft_strlen(substr))
		return ((char *)str);
	while (*s != '\0' && n--)
	{
		if (*s++ == *ss)
		{
			res = s - 1;
			if (ft_check_substr(s, ++ss))
				return ((char *)res);
			ss = substr;
		}
	}
	return (NULL);
}
