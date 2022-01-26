/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:17:48 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:26:35 by cflorind         ###   ########.fr       */
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
Checks if a character is a digit (0 through 9).
*/
int	ft_isdigit(int c)
{
	return (48 <= c && c <= 57);
}
