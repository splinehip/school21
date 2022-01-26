/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:12:04 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/29 15:41:22 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_ft_tobase.h"

static t_ulli	get_base_10(unsigned int base, char *n_str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	t_ulli	res;

	i = 0;
	len = 0;
	res = 0;
	while (n_str[len + 1] != 0)
		len++;
	while (n_str[i] != 0)
	{
		j = 0;
		while (g_base[base][j] != n_str[i] && g_base[base][j] != 0)
			j++;
		if (g_base[base][j] == 0)
			return (0);
		res += j * ft_uintpow(base, len - i);
		i++;
	}
	return (res);
}

static char	*get_to_base(unsigned int base, t_ulli n)
{
	char	*res;
	char	*tmp;

	res = NULL;
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		tmp = res;
		res = ft_strljoinchr(res, g_base[base][n % base]);
		n /= base;
		if (tmp != NULL)
			free(tmp);
		if (res == NULL)
			return (NULL);
	}
	return (res);
}

/*
Arguments:
base - the base of the system in which the number is represented.
tobase - the base of the system to which the number must be converted.
... is the number to be represented in the tobase number system, maybe
passed as unsingned int or char *str. If passed as unsingned int
then 10 must be passed to first base argument.
MIN BASE 2  -  MAX BASE 64.

Returned values:
The function returns a string representing a number in the specified number
system. If it was not possible to allocate memory or perform a conversion,
then NULL.

Description:
The function converts a number from one number system to another.
The returned item is represented by a string. If the conversion failed, it
returns NULL.
If the given number has a base not equal to 10 and in
the transferred string contains characters other than the numeral system
characters, then it will be returned NULL.
*/
char	*ft_tobase(unsigned int base, unsigned int tobase, ...)
{
	va_list	ap;
	t_ulli	n;
	char	*n_str;
	char	*res;

	res = NULL;
	n_str = NULL;
	va_start(ap, tobase);
	if (base == 10)
		n = va_arg(ap, t_ulli);
	else
		n_str = ft_strdup(va_arg(ap, char *));
	if (base != 10 && n_str == NULL)
		return (NULL);
	va_end(ap);
	if (base != 10)
	{
		n = get_base_10(base, n_str);
		if (n == 0 && ft_strlen(n_str) != 1 && n_str[0] != '0')
			return (NULL);
	}
	res = get_to_base(tobase, n);
	if (n_str != NULL)
		free(n_str);
	return (res);
}
