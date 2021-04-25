/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:25:23 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 23:59:51 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Аргументы:
lst - указатель на указатель элемента списка.
new - указатель на новый элемент списка который необходимо добавить.

Возвращаемые значение:
Нет.

Описание:
Функция находит последний элемент переданного списка lst и добавляет в его
конец новый элемент new.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst != NULL)
	{
		if (*lst != NULL && new != NULL)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
		{
			if (*lst == NULL && new != NULL)
				*lst = new;
			if (*lst != NULL && new == NULL)
			{
				new = (t_list *)ft_calloc(1, sizeof(t_list));
				last = *lst;
				last->next = new;
			}
		}
	}
}
