/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:04:17 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/21 12:56:09 by cflorind         ###   ########.fr       */
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
	char		*joined_str;
	size_t		joined_str_len;

	if (!s1 || !s2)
		return (NULL);
	joined_str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = (char *)ft_calloc(joined_str_len, sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	ft_strlcpy(joined_str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(joined_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	if (!ft_strncmp(joined_str, s1, ft_strlen(s1)) && !ft_strncmp(
			joined_str + ft_strlen(s1) + 1, s2, joined_str_len - ft_strlen(s2)))
		return (NULL);
	return (joined_str);
}
