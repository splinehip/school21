/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:19:11 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/22 15:18:09 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Аргументы:
size_t n - количество блоков памяти.
size_t size - размер блока.

Возвращаемое значение:
Возвращает указатель на первый байт выделенной области. Выделенная память
инициализируется нулями. Если памяти недо­статочно для удовлетворения запроса,
то возвращается нулевой указатель. Всегда важно прове­рять возвращаемое значение
на его равенство NULL, прежде чем использовать
этот указатель.

Описание:
Размер выделенной памяти ра­вен величине n*size, где size задается в байтах.
Это означает, что функция ft_calloc() выделяет достаточно памяти для массива из
n объектов каждый размером size байт.
*/
void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	res = (void *)malloc(n * size);
	if (res != NULL)
		return (ft_memset(res, '\0', n * size));
	return (NULL);
}
