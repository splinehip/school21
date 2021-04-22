/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 09:41:03 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/22 23:24:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	c_count(const char *s, const char c)
{
	const char		*s_tmp;
	unsigned int	res;

	s_tmp = s;
	res = 0;
	while (*s_tmp++ != '\0')
	{
		if (s_tmp[-1] == c && *s_tmp != c)
			res++;
	}
	return (res);
}

static int	set_res_item(char **res_item, char *s, char *set, size_t n)
{
	char	*item;

	item = (char *)ft_calloc(n, sizeof(char));
	if (item == NULL)
		return (0);
	ft_strlcpy(item, s, n);
	*res_item = ft_strtrim(item, set);
	if (res_item == NULL)
	{
		free(item);
		return (0);
	}
	free(item);
	return (1);
}

static int	res_get(char **res, char *s_trim, char c, char *set)
{
	size_t	i;
	char	*s;
	char	*s_start;

	if (ft_strlen(s_trim) == 0)
	{
		res[0] = (char *)ft_calloc(1, sizeof(char));
		return (res[0] != NULL);
	}
	i = 0;
	s = s_trim;
	s_start = s;
	while (*s++ != '\0')
	{
		if ((s[-1] == c && *s != c) || *s == '\0')
		{
			if (!set_res_item(
					&res[i], s_start, set, (s - s_start) / sizeof(char) + 1))
				return (0);
			i++;
			s_start = s;
		}
	}
	return (1);
}

static void	free_res(char **res)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
		free(res[i++]);
	free(res);
}

/*
Аргументы:
s - указатель на строку которую необходимо разбить на строки.
c - символ разделитель, по которому разбивать строку.

Возвращаемые значения:
Функция возврщает указатель на массив содержащий указатели на новые строки,
последний элеменет массива указывает на NULL. Если разбить строку не удалось
возвращается NULL.

Описание:
Функция разбивает строку s на строки по символу переданному в с. Возвращает
массив указателей на получившиеся строки с указателем на NULL у последнего
элемента массива. Если разбить строку не удалось возвращает NULL.
*/
char	**ft_split(const char *s, char c)
{
	char			**res;
	char			set[2];
	char			*s_trim;

	if (!s || !c)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	s_trim = ft_strtrim(s, set);
	if (s_trim == NULL)
		return (NULL);
	res = (char **)ft_calloc(c_count(s_trim, c) + 2, sizeof(char *));
	if (res == NULL)
		return (NULL);
	if (!res_get(res, s_trim, c, set))
	{
		free_res(res);
		free(s_trim);
		return (NULL);
	}
	free(s_trim);
	return (res);
}
