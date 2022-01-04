/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:00:26 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/04 17:19:57 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "actions_handler.h"

static inline t_redirect	*append_redirect(t_redirects *redirects)
{
	t_redirect	*tmp;

	if (redirects->len == false)
	{
		redirects->item = ft_calloc(1, sizeof(t_redirect));
		if (redirects->item)
			redirects->len += 1;
		return (redirects->item);
	}
	tmp = redirects->item;
	redirects->item = ft_calloc(redirects->len + 1, sizeof(t_redirect));
	ft_memcpy(redirects->item, tmp, sizeof(t_redirect) * redirects->len);
	free(tmp);
	if (redirects->item)
	{
		redirects->len += 1;
		return (&redirects->item[redirects->len - 1]);
	}
	return (NULL);
}

static inline void	update_str(char **str, int i, int j)
{
	char	*tmp;

	tmp = str[i];
	while (str[j])
		str[i++] = str[j++];
	str[i] = NULL;
	free(tmp);
}

static inline void	do_extract(
	t_redirects *redirects, char **str, int i, int type)
{
	t_redirect	*new;

	new = append_redirect(redirects);
	if (new == NULL)
		return ;
	new->type = type;
	if (ft_strlen(str[i]) == 1
		|| (ft_strlen(str[i]) == 2 && str[i][0] == str[i][1]))
	{
		new->target = str[i + 1];
		update_str(str, i, i + 2);
	}
	else
	{
		new->target = ft_strtrim(str[i], "<>");
		update_str(str, i, i + 1);
	}
}

inline void	extract_redirects(t_redirects *redirects, char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i][0] == left_corner)
		{
			if (str[i][1] == left_corner)
				do_extract(redirects, str, i, read_input);
			else
				do_extract(redirects, str, i, input);
			i = 0;
		}
		else if (str[i][0] == right_corner)
		{
			if (str[i][1] == right_corner)
				do_extract(redirects, str, i, output_append);
			else
				do_extract(redirects, str, i, output);
			i = 0;
		}
		i++;
	}
}

inline void	add_redirects(t_redirects *redirects, int type, char *target)
{
	t_redirect	*new;

	new = append_redirect(redirects);
	if (new == NULL)
		return ;
	new->type = type;
	new->target = target;
}
