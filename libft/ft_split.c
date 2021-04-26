/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 09:41:03 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/26 16:41:52 by cflorind         ###   ########.fr       */
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
Arguments:
s - pointer to the string to be split into lines.
c - the delimiter character by which to split the string.

Returned values:
The function returns a pointer to an array containing pointers to new lines,
the last element of the array points to NULL. If the line break fails
NULL is returned.

Description:
The function splits the string s into lines according to the character passed
to s. Returns an array of pointers to the resulting strings with a pointer
to NULL for the last one array element. Returns NULL if the string cannot be
split.
*/
char	**ft_split(const char *s, char c)
{
	char			**res;
	char			set[2];
	char			*s_trim;

	if (!s || !c)
		return (NULL);
	if (!ft_strlcpy(set, &c, 2))
		return (NULL);
	s_trim = ft_strtrim(s, set);
	if (s_trim == NULL || ft_strlen(s_trim) == 0)
	{
		res = (char **)ft_calloc(1, sizeof(char *));
		return (res);
	}
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
