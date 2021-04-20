/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:08:26 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/20 14:23:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int atoi (const char *str);

Аргументы:
str – указатель на строку, которую необходимо преобразовать в число.

Возвращаемое значение:
Функция возвращает число - результат преобразование строки, если в начале
строки содержится число. Если в начале строки стоит символ не являющейся
цифрой, то функци возвращает ноль.

Описание:
Функция atoi () преобразует строку, на которую указывает аргумент str, в число
типа int. Преобразование заканчивается, когда встречается символ не являющейся
цифрой или, когда будет преобразована вся строка. Если первый символ строки не
цифра, то функция вернет 0 и завершит работу.
Строка должна начинаться или непосредственно с числовой последовательности,
или с любого сочетания пробельных символов.

Если число в строке превышает максимальный или минимальный размер числа типа
int, то функция возвращает соответственно максимально или минимально допустимое
число для типа int. Возвращаемая величина зависит от аппаратной платформы на
которой запускается программа.

От функции atol () отличается типом возвращаемого числа и как следствие
макимальной длинной преобразуемой строки. Для atoi возвращаемое число имеет тип
int, а соответственно разрядность 16 или 32 бита в зависимости от аппаратной
платформы, на которой запускается программа. Для atol возвращаемое число имеет
тип long int, который всегда 32 разрядный, не зависимо от архитектуры
процессора.

Так, на пример, в результате преобразования строки "217bg12" будет получено
число 217, а при преобразовании строки "b237пр" будет получено число 0.
*/
int	ft_atoi(const char *str)
{
	int			n;
	int			res;
	const char	*s;

	n = 0;
	res = 0;
	s = str;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			n = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	if (n % 2 != 0)
		res *= -1;
	return (res);
}
