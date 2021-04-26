/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:04:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 13:59:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Аргументы:
s1 - указатель на первую строку.
s2 - указатель на вторую строку.

Возвращаемые значения:
Возвращает указатель на новую, конкатенированную строку, NULL если не удалось
выполнить конкатенацию строк.

Описание:
Функция выполняет объединение двух строк (конкатенацию) и возвращает указатель
на итоговую строку. Если не удалось объеденить строки возвращает NULL.
*/
char	*ft_strjoin(const char *s1, char const *s2)
{
	char		*res;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	if (*s1 == '\0' && *s2 == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)ft_calloc(len, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len);
	ft_strlcpy(res + ft_strlen(s1), s2, len);
	if (ft_strncmp(res, s1, ft_strlen(s1)) || ft_strncmp(
			res + ft_strlen(s1), s2, ft_strlen(s2)))
		return (NULL);
	return (res);
}
