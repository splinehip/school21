/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:37:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/24 12:26:01 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Arguments:
lst is a pointer to a list item.
del is a pointer to the function to remove the content field of the list item.

Returned value:
Not.

Description:
The function gets an element of the passed list lst and applies to its field
content function del, and then deletes the element itself.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
