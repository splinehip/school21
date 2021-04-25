/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:07:30 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 11:38:57 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Аргументы:
lst - указатель на указатель первого элемента списка.
new - указатель на новый элемент списка который необходимо добавить.

Возвращаемые значение:
Нет.

Описание:
Функция получает первый элемент переданного списка lst и добавляет перед ним
новый элемент new.
*/
void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (list && *list && new)
	{
		new->next = *list;
		*list = new;
	}
}
