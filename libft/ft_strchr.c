/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:09:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/22 02:48:47 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Аргументы:
str – указатель на строку, в которой будет осуществляться поиск.
c – код искомого символа.

Возвращаемое значение:
Указатель на искомый символ, если он найден в строке str, иначе NULL.

Описание:
Функция ищет первое от НАЧАЛА строки вхождения символа, код которого указан в
аргументе c, в строке, на которую указывает аргумент str.
*/
char	*ft_strchr(const char *str, int c)
{
	const char	*s;

	s = str;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
