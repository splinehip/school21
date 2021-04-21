/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 08:50:48 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/21 09:34:46 by cflorind         ###   ########.fr       */
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	subs_len;

	if (!s || len == 0)
		return (NULL);
	subs_len = ft_strlen(s) + 1 - start;
	subs = (void *)ft_calloc(subs_len, sizeof(char));
	if (subs == NULL)
		return (NULL);
	ft_strlcpy(subs, s + start, subs_len);
	if (!ft_strncmp(subs, s + start, subs_len))
		return (subs);
	return (NULL);
}
