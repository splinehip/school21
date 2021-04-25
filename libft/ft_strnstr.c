/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:50:22 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 19:35:30 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Аргументы:

str – указатель на строку, в которой ведется поиск.
substr – указатель на искомую строку.
n - количество символов для поиска.

Возвращаемое значение:
NULL – если строка substr не входит в строку str. Указатель на первое вхождение
строки substr в строку str.

Описание:
Функция strnstr ищет первое вхождение строки (за исключением символа конца
строки), на которую указывает аргумент substr, в строку , на которую указывает
аргумент str. Поиск в str выполнятестся не блоее n символов. Если строка substr
имеет нулевую длину, то функция вернет указатель на начало строки str.
*/
char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	const char	*res;
	const char	*s;
	const char	*ss;

	if (str == NULL || substr == NULL || n < ft_strlen(substr))
		return (NULL);
	s = str;
	ss = substr;
	if (!ft_strlen(substr))
		return ((char *)str);
	while (*s && ft_strlen(substr) <= n--)
	{
		if (*s++ == *ss)
		{
			ss++;
			res = s - 1;
			if (!ft_strncmp(s, ss, ft_strlen(ss)))
				return ((char *)res);
			ss = substr;
		}
	}
	return (NULL);
}
