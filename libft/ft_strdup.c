/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:37:23 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 12:40:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Аргументы:
str – указатель на дублируемую строку.

Возвращаемое значение:
NULL – если не удалость выделить память под новую строку или скопировать строку
на которую указывает аргумент str. Указатель на дублирующую строку.

Описание:
Функция strdup дублирует строку, на которую указывает аргумент str.
Память под дубликат строки выделяется с помощью функции malloc, и по окончанию
работы с дубликатом должна быть очищена с помощью функции free.
*/
char	*ft_strdup(char *str)
{
	size_t	str_len;
	char	*str_dup;

	str_len = ft_strlen(str) + 1;
	str_dup = (char *)ft_calloc(str_len, sizeof(char));
	if (str_dup != NULL)
	{
		ft_strlcpy(str_dup, str, str_len);
		if (!ft_strncmp(str_dup, str, str_len))
			return (str_dup);
	}
	return (NULL);
}
