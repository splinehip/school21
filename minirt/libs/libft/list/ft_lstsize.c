/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:11:36 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/24 12:25:38 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Arguments:
lst is a pointer to a list item.

Returned value:
The number of items in the lst list.

Description:
The function receives a pointer to the first element of the passed list lst goes
to its end and returns the resulting number of elements in the list.
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
