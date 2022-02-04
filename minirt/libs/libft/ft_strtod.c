/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:35:56 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/04 17:19:24 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

#include "libft.h"

typedef struct s__vars
{
	double	number;
	int		exponent;
	int		negative;
	char	*p;
	double	p10;
	int		n;
	int		num_digits;
	int		num_decimals;
}	t__vars;

static inline void	init__vars(t__vars *vars)
{
	while ((*vars->p >= '\t' && *vars->p <= '\r') || *vars->p == ' ')
		vars->p++;
	vars->negative = 0;
	if (*vars->p == '-')
		vars->negative = 1;
	if (*vars->p == '+')
		vars->p++;
	vars->number = 0.;
	vars->exponent = 0;
	vars->num_digits = 0;
	vars->num_decimals = 0;
}

static inline void	check_left_half(t__vars *vars)
{
	while (ft_isdigit(*vars->p))
	{
		vars->number = vars->number * 10. + (*vars->p - '0');
		vars->p++;
		vars->num_digits++;
	}
	if (*vars->p == '.')
	{
		vars->p++;
		while (ft_isdigit(*vars->p))
		{
			vars->number = vars->number * 10. + (*vars->p - '0');
			vars->p++;
			vars->num_digits++;
			vars->num_decimals++;
		}
		vars->exponent -= vars->num_decimals;
	}
}

static inline void	check_right_half(t__vars *vars)
{
	if (vars->negative)
		vars->number = -vars->number;
	if (*vars->p == 'e' || *vars->p == 'E')
	{
		vars->negative = 0;
		if (*++vars->p == '-')
			vars->negative = 1;
		if (*++vars->p == '+')
			vars->p++;
	}
	vars->n = 0;
	while (ft_isdigit(*vars->p))
	{
		vars->n = vars->n * 10 + (*vars->p - '0');
		vars->p++;
	}
	if (vars->negative)
		vars->exponent -= vars->n;
	else
		vars->exponent += vars->n;
}

static inline void	check_exponent(t__vars *vars)
{
	vars->p10 = 10.;
	vars->n = vars->exponent;
	if (vars->n < 0)
		vars->n = -vars->n;
	while (vars->n)
	{
		if (vars->n & 1)
		{
			if (vars->exponent < 0)
				vars->number /= vars->p10;
			else
				vars->number *= vars->p10;
		}
		vars->n >>= 1;
		vars->p10 *= vars->p10;
	}
}

/*
Arguments for func family:
double strtod(const char *nptr, char **endptr);
float strtof(const char *nptr, char **endptr);
long double strtold(const char *nptr, char **endptr);

nptr - is pointer to source string that will converted to floating number.
endptr - is pointer to pointer which the will store the ended element of number
in source string.

Description
The strtod(), strtof(), and strtold() functions convert the initial portion of
the string pointed to by nptr to double, float, and long double representation,
respectively.

The expected form of the (initial portion of the) string is optional leading
white space as recognized by isspace(3), an optional plus ('+') or minus sign
('-') and then either (i) a decimal number, or (ii) a hexadecimal number, or
(iii) an infinity, or (iv) a NAN (not-a-number).

A decimal number consists of a nonempty sequence of decimal digits possibly
containing a radix character (decimal point, locale-dependent, usually '.'),
optionally followed by a decimal exponent. A decimal exponent consists of an
'E' or 'e', followed by an optional plus or minus sign, followed by a nonempty
sequence of decimal digits, and indicates multiplication by a power of 10.

A hexadecimal number consists of a "0x" or "0X" followed by a nonempty sequence
of hexadecimal digits possibly containing a radix character, optionally followed
by a binary exponent. A binary exponent consists of a 'P' or 'p', followed by an
optional plus or minus sign, followed by a nonempty sequence of decimal digits,
and indicates multiplication by a power of 2. At least one of radix character
and binary exponent must be present.

An infinity is either "INF" or "INFINITY", disregarding case.

A NAN is "NAN" (disregarding case) optionally followed by '(', a sequence of
characters, followed by ')'. The character string specifies in an
implementation-dependent way the type of NAN.

Return Value
These functions return the converted value, if any.
If endptr is not NULL, a pointer to the character after the last character used
in the conversion is stored in the location referenced by endptr.

If no conversion is performed, zero is returned and the value of nptr is stored
in the location referenced by endptr.

If the correct value would cause overflow, plus or minus HUGE_VAL (HUGE_VALF,
HUGE_VALL) is returned (according to the sign of the value), and ERANGE is
stored in errno. If the correct value would cause underflow, zero is returned
and ERANGE is stored in errno.
*/
double	ft_strtod(const char *str, char **endptr)
{
	t__vars	vars;

	vars.p = (char *) str;
	init__vars(&vars);
	check_left_half(&vars);
	if (vars.num_digits == 0)
	{
		errno = ERANGE;
		return (0.0);
	}
	check_right_half(&vars);
	if (vars.exponent < DBL_MIN_EXP || vars.exponent > DBL_MAX_EXP)
	{
		errno = ERANGE;
		return (HUGE_VAL);
	}
	check_exponent(&vars);
	if (vars.number == HUGE_VAL)
		errno = ERANGE;
	if (endptr)
		*endptr = vars.p;
	return (vars.number);
}
