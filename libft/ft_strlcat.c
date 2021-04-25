/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:32:44 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 18:31:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t max)
{
	size_t	str_len;

	str_len = 0;
	while (str_len < max)
	{
		if (str[str_len] == '\0')
			return (str_len);
		str_len++;
	}
	return (max);
}

/*
Аргументы:

dest – указатель на массив в который будет добавлена строка.
src – указатель на массив из которого будет скопирована строка.
n – размер массива dest.

Возвращаемое значение:
Функция возвращает сумму длин строк dest и src.

Описание:
Функция добавляет в строку, на которую указывает аргумент dest, строку, на
которую указывает аргумент src, пока не встретится символ конца строки или пока
не будет добавлено n - заполненная часть dest - 1 символов.
Гарантируется установка символа конца строки в конце объединенных строк.
Для корректной работы функции, ей необходимо передавать только нультерминальные
строки.
Если строки перекрываются, результат объединения будет не определен.
*/
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d_size;
	size_t	s_size;

	if (dest == NULL || src == NULL)
		return (0);
	d_size = ft_strnlen(dest, n);
	s_size = ft_strlen(src);
	if (d_size == n)
		return (s_size + n);
	if (s_size < n - d_size)
		ft_memcpy(dest + d_size, src, s_size + 1);
	else
	{
		ft_memcpy(dest + d_size, src, n - d_size);
		dest[n - 1] = '\0';
	}
	return (d_size + s_size);
}
