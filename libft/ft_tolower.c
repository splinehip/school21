/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:23:50 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:51:01 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
int c - the code of the character to be converted to lowercase.

Return value:
Returns the lowercase equivalent of c if
c is an uppercase letter. Otherwise, c is returned unchanged.

Description:
Checks if a character is a letter, if so, converts to lowercase.
*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
