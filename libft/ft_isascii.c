/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:39:22 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/20 15:47:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Аргументы:
int c - код символа, который необходимо проверить.

Возвращаемое значение:
Возвращаются ненулевые значения, если проверяемый символ c попадает в
соответствующий класс символов (соответствуют 7-битному коду US-ASCII-символов
между 0 и восьмеричным 0177 включительно (или являются US-ASCII-символами)),
в противном случае возвращается ноль.

Описание:
Проверяет, является ли c 7-битным unsigned char, значение которого попадает в
таблицу символов ASCII. Эта функция является расширением BSD и расширением SVID.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
