/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:15:39 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:47:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
str1, str2 - pointers to compared strings.
size_t n - number of characters to compare.

Returned value:
0 - if the first n characters of the compared strings are identical.

A positive number - if there are differences in the first n characters of the
compared strings and the code of the first different character in string str1 is
greater than the code of the character by the same positions in string str2.

Negative number - there are differences and a code in the first n characters of
the compared strings the first different character in string str1 is less than
the character code on the same positions in string str2.

If n characters were checked, or if both compared strings ended, and
there were no differences, then the comparison stops and zero is returned.
*/
int	ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	const char	*s1;
	const char	*s2;

	if (str_1 == NULL || str_2 == NULL || n == 0)
		return (0);
	s1 = str_1;
	s2 = str_2;
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n--)
	{
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
