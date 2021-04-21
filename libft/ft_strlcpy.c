/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:31:35 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/21 11:02:49 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Аргументы:
dest – указатель на строку, в которую будут скопированы данные.
src – указатель на строку источник копируемых данных.
l - размер строки dest.

Возвращаемое значение:
Функция возвращает размер строки src.

Описание:
Функция ft_strlcpy копирует из строки src в буфер dest не более чем l - 1
символов и гарантированно устанавливает в конец строки нулевой символ.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t l)
{
	size_t		count;

	if (!dest || !src)
		return (0);
	if (l == 0)
		return (ft_strlen(src));
	count = 0;
	while (src[count] != '\0' && count < l - 1)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}
