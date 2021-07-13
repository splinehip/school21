/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:25:23 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/24 12:26:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Arguments:
lst is a pointer to a pointer to a list item.
new - a pointer to a new list item to be added.

Returned value:
Not.

Description:
The function finds the last element of the passed list lst and adds to it
end new element new.
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
				(*lst)->next = new;
			}
		}
	}
}
