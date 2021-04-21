/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:24:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/20 15:28:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Аргументы:
int c - код символа, который необходимо проверить.

Возвращаемое значение:
Возвращаются ненулевые значения, если проверяемый символ c попадает в
соответствующий класс символов, в противном случае возвращается ноль.

Описание:
Проверяет символ на принадлежность к текстовым символам; вызов эквивалентен
(isalpha(c) || isdigit(c)).
*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}