/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:05:22 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:27:12 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
int c - the code of the character to be checked.

Return value:
Nonzero values are returned if the checked character c falls within
corresponding character class (codes 32 - 126)),
otherwise, zero is returned.

Description:
Checks if a character is printable (including space).
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
