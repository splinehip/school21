/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:39:22 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:26:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
int c - the code of the character to be checked.

Return value:
Nonzero values are returned if the checked character c falls within
corresponding character class (correspond to 7-bit US-ASCII characters
between 0 and 0177 octal inclusive (or are US-ASCII characters)),
otherwise, zero is returned.

Description:
Checks if c is a 7-bit unsigned char whose value falls into
ASCII character table. This feature is a BSD extension and an SVID extension.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
