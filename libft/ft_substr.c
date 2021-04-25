/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 08:50:48 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 21:23:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Аргументы:
s - указатель на исходную строку.
start - индекс символа в исходной строке, с которого начинать копирование.
len - максимальная длина для копирования.

Возвращаемое значение:
Возвращает указатель на скопированную подстроку или NULL если копирование не
удалось.

Описание:
Функция копирует подстроку из исходной строки s начиная с индекса start и
длиной не более len. При успехе возвращает указатель на скопированную подстроку.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;

	if (s == NULL || len == 0)
		return (NULL);
	if (start >= ft_strlen(s) + 1)
		return ((char *)ft_calloc(1, sizeof(char)));
	subs = (char *)ft_calloc(len + 1, sizeof(char));
	if (subs == NULL)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	if (!ft_strncmp(subs, s + start, len))
		return (subs);
	return (NULL);
}
