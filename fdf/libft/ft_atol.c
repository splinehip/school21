/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:55:45 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/28 15:59:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
str is a pointer to the string to be converted to a number.

Returned value:
The function returns a number - the result of converting a string, if at the
beginning lines content number. If at the beginning of a line there is a
character that is not digit, the function returns zero.

Description:
The atol() function converts the argument pointed to by str to a number
of type long int. A transformation is encountered when a character that is not
a digit or when the entire string is converted. If the first character of the
string is not digit, then the function will return 0 and exit.
The string must start or directly with a numeric stick,
or any combination of whitespace characters.

If the number is in the range of the maximum type or minimum size of the number
long int, then the function returns, respectively, the maximum or minimum
allowed number for int type. The returned value depends on the hardware platform
at which the program runs.

It differs from the atoi() function in the type of the returned number and as
a consequence the maximum long string to convert. For atoi, the return number
is of type int, and accordingly 16 or 32 bits, depending on the hardware
the platform on which the program runs. For atol, the returned number is
long int type, which is always 32-bit, regardless of architecture
CPU.

So, for example, as a result of converting the string "217bg12" you will get
number 217, and when converting the string "b237pr", the number 0 will be
obtained.
*/
long int	ft_atol(const char *str)
{
	long int	n;
	long int	res;
	const char	*s;

	n = 0;
	res = 0;
	s = str;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			n = 1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	if (n)
		res *= -1;
	return (res);
}
