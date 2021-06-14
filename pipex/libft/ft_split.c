/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 09:41:03 by cflorind          #+#    #+#             */
/*   Updated: 2021/06/14 15:34:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	strs_qty(const char *s, const char c)
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

static char	*get_s_trim(const char *s, char *set)
{
	char	*res;

	res = ft_strtrim(s, set);
	if (res == NULL)
		return (res);
	if (ft_strlen(res) == 0)
	{
		free(res);
		res = NULL;
	}
	return (res);
}

static int	get_res(char **res, char *s_trim, char c, char *set)
{
	size_t	i;
	char	*s;
	char	*s_start;
	char	*item;

	i = 0;
	s = s_trim;
	s_start = s;
	while (*s++ != '\0')
	{
		if ((s[-1] == c && *s != c) || *s == '\0')
		{
			item = (char *)ft_calloc((s - s_start) / sizeof(char) + 1,
					sizeof(char));
			if (!ft_strlcpy(item, s_start, (s - s_start) / sizeof(char) + 1))
				return (0);
			res[i++] = ft_strtrim(item, set);
			free(item);
			if (res[i - 1] == NULL)
				return (0);
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
	char	**res;
	char	set[2];
	char	*s_trim;

	if (s == NULL || *s == 0)
		return ((char **)ft_calloc(1, sizeof(char *)));
	if (c == 0)
	{
		res = (char **)ft_calloc(2, sizeof(char *));
		if (res != NULL)
			res[0] = ft_strdup(s);
		return (res);
	}
	set[0] = c;
	set[1] = 0;
	s_trim = get_s_trim(s, set);
	if (s_trim == NULL)
		return ((char **)ft_calloc(1, sizeof(char *)));
	res = (char **)ft_calloc(strs_qty(s_trim, c) + 2, sizeof(char *));
	if (res == NULL)
		return (NULL);
	if (!get_res(res, s_trim, c, set))
		free_res(res);
	free(s_trim);
	return (res);
}
