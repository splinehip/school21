/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:46:19 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/08 18:21:19 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**init_split_res(const char *s, size_t i, size_t j)
{
	char	**res;
	size_t	start;

	start = 0;
	while (s[j] != 0)
	{
		if (s[j + 1] == 0)
			i++;
		else if (s[j] == '%' && s[start] != '%')
		{
			i++;
			start = j--;
		}
		else if (ft_printf_isconvsymbol(s[j]) && s[start] == '%')
		{
			while (!ft_printf_isconvsymbol(s[++j]) && s[j] != 0)
				;
			i++;
			start = j + 1;
		}
		j++;
	}
	res = (char **)ft_calloc(i + 1, sizeof(char **));
	return (res);
}

static int	set_split_res(const char *s, char **res, size_t i, size_t j)
{
	size_t	start;

	start = 0;
	while (s[j] != 0)
	{
		if (s[j + 1] == 0)
			res[i++] = ft_substr(s, start, j - start + 1);
		else if (s[j] == '%' && s[start] != '%')
		{
			res[i++] = ft_substr(s, start, j - start);
			start = j--;
		}
		else if (ft_printf_isconvsymbol(s[j]) && s[start] == '%')
		{
			while (!ft_printf_isconvsymbol(s[++j]) && s[j] != 0)
				;
			res[i++] = ft_substr(s, start, j - start + 1);
			start = j + 1;
		}
		if (i != 0 && res[i - 1] == NULL)
			return (0);
		j++;
	}
	return (1);
}

static char	**ssplit(const char *s)
{
	char	**res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = init_split_res(s, i, j);
	if (res == NULL)
		return (NULL);
	if (set_split_res(s, res, i, j) == 0)
	{
		while (res[i] != NULL)
			free(res[i++]);
		free(res);
		return (NULL);
	}
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	char	*res;
	char	**ss;
	size_t	len;

	va_start(ap, s);
	ss = ssplit(s);
	res = NULL;
	res = ft_printf_getres((const char **)ss, res, ap);
	va_end(ap);
	len = 0;
	while (ss[len] != NULL)
		free(ss[len++]);
	free(ss);
	if (res == NULL)
		return (0);
	len = (int)ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}
