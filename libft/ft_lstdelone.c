/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:37:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/25 11:45:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Аргументы:
lst - указатель на элемент списка.
del - указатель на функцию удаления поля content элемента списка.

Возвращаемые значение:
Нет.

Описание:
Функция получает элемент переданного списка lst и применяет к его полю
content функцию del, после чего удаляет сам элемент.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}