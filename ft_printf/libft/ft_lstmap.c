/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:25:28 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:32:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
lst is a pointer to a list item.
f - pointer to the function for processing the content field of the list item
del is a pointer to the function to remove the content field of the list item.

Returned value:
Pointer to a new list with the results of processing the content field by the
function q f from source list. If processing fails, the new list is deleted and
NULL is returned.

Description:
The function gets an element of the passed list lst and applies to its field
content function f, after which it adds the element to the new list and to its
field content sets the result of processing the content field from the original
element list. The function iterates through all descendants of the list item lst
until it reaches to the end of the list. If it was not possible to process the
content field at least one of elements of the original list, new to the content
field of the elements of the new list the del function is applied, the new list
is removed and NULL is returned.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*res;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	tmp = lst;
	res = ft_lstnew(f(tmp->content));
	if (res)
	{
		tmp = tmp->next;
		while (tmp != NULL)
		{
			new = ft_lstnew(f(tmp->content));
			if (new != NULL)
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
