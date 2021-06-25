/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:13:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/24 12:25:57 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../libft.h"

/*
Arguments:
lst is a pointer to a list item.
f - pointer to the function for processing the content field of the list item.

Returned value:
Not.

Description:
The function gets an element of the passed list lst and applies to its field
content function f. The function processes all descendants of the lst list
element so far will not make it to the end of the list.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst && f)
	{
		tmp = lst;
		while (tmp)
		{
			f(tmp->content);
			tmp = tmp->next;
		}
	}
}
