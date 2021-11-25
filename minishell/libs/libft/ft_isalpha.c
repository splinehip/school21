/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:39:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:25:37 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
int c - the code of the character to be checked.

Returned value:
Nonzero values are returned if the checked character c falls within
the appropriate character class, otherwise zero is returned.

Description:
Checks a character for alphabetic characters in standard
in the "C" environment this is equivalent to (isupper (c) || islower (c)).
On some systems there may be additional characters for which isalpha () is
true, i.e. letters can be neither uppercase nor lowercase.
*/
int	ft_isalpha(int c)
{
	return ((65 <= c && c <= 90) || (97 <= c && c <= 122));
}
