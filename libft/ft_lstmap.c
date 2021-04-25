/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:25:28 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 11:56:37 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Аргументы:
lst - указатель на элемент списка.
f - указатель на функцию обработки поля content элемента списка
del - указатель на функцию удаления поля content элемента списка.

Возвращаемые значение:
Указатель на новый список с результатами обработки поля content функциеq f из
исходного списка. Если обработка не удалась, новый список удаляется и
возвращается NULL.

Описание:
Функция получает элемент переданного списка lst и применяет к его полю
content функцию f, после чего добавляет элемент в новый список и в его поле
contentпомещает результат обработки поля content из элемента исходного
списка. Функция проходит по всем потомкам элемента списка lst пока не дойдет
до конца списка. Если не удалось обработать поле content хотябы одного из
элементов исходного списка, новый к полю content элементов нового списка
применяется функция del, новый список удаляется и возвращается NULL.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	res = ft_lstnew(f(tmp->content));
	if (res)
	{
		tmp = tmp->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->content));
			if (new)
				ft_lstadd_back(&res, new);
			else
			{
				ft_lstclear(&res, del);
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (res);
}
