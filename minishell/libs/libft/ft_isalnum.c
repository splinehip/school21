/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:24:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:24:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
int c - the code of the character to be checked.

Return value:
Nonzero values are returned if the checked character c falls within
the appropriate character class, otherwise zero is returned.

Description:
Checks a character to be a text character; the call is equivalent
(isalpha (c) || isdigit (c)).
*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
