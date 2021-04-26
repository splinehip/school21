/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:14:05 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:51:21 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
int c - character code to be converted to upper case.

Return value:
Returns the uppercase equivalent of c if
c is a lowercase letter. Otherwise, c is returned unchanged.

Description:
Checks if a character is a letter, if so, converts to uppercase.
*/
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
