/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:01:34 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/21 23:49:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Аргументы:
buf – указатель на заполняемый массив.
с – код символа для заполнения.
l – размер заполняемой части массива в байтах.

Возвращаемое значение:
Функция возвращает указатель на заполняемый массив buf.

Описание:
Функция заполняет первые l байт области памяти, на которую указывает аргумент
buf, символом, код которого указывается аргументом c. Если buf указывает на
NULL - функция вернет NULL.
*/
void	*ft_memset(void *buf, int c, size_t l)
{
	unsigned char	*buf_tmp;

	if (!buf)
		return (NULL);
	buf_tmp = (unsigned char *)buf;
	while (l--)
	{
		*buf_tmp++ = (unsigned char)c;
	}
	return (buf);
}
