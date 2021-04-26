/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:54:33 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:29:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
lst is a pointer to a pointer to a list item.
del is a pointer to the function to remove the content field of the list item.

Returned value:
Not.

Description:
The function gets an element of the passed list lst and applies to its field
content function del and removes the list item itself. Function sequentially
removes all descendants of the passed list item lst until it reaches the end
list.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = tmp->next;
			ft_lstdelone(tmp, del);
		}
	}
}
