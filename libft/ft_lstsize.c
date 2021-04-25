/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:11:36 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 12:03:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Аргументы:
lst - указатель на элемент списка.

Возвращаемые значение:
Количество элементов в списке  lst.

Описание:
Функция получает укатель на первый элемент переданного списка lst проходит до
его конца и возвращает полученное количество элементов списка.
*/
int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*tmp;

	res = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			tmp = tmp->next;
			res++;
		}
	}
	return (res);
}
