/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:50:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/21 17:37:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	inset(const char *set, const char c)
{
	const char	*s;

	s = set;
	while (*s != '\0')
	{
		if (*s++ == c)
			return (1);
	}
	return (0);
}

/*
Аргументы:
s1 - указатель на строку в которой необходимо удалить символы.
set - указатель на строку с символами для удаления.

Возвращаемые значения:
Возвращается указатель на новую строку без симоволов из set в начале и конце
строки. Если не удалось выделить память - NULL.

Описание:
Функция удаляет из исходной строки, в начале и конце строки, символы из set и
возвращает указатель на новую, обрезанную строку. Если не удалось выделить
память или скопировать строку возвращается NULL.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	rigth;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	left = 0;
	rigth = ft_strlen(s1);
	while (s1[left] != '\0' && inset(set, s1[left]))
	{
		left++;
	}
	while (rigth--)
	{
		if (!inset(set, s1[rigth]))
			break ;
	}
	res = (char *)ft_calloc(rigth - left + 2, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1 + left, (rigth - left) + 2);
	if (!ft_strncmp(res, s1 + left, rigth - left + 1))
		return (res);
	return (NULL);
}
