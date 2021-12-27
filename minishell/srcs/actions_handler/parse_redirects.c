/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:00:26 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/27 14:06:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "actions_handler.h"

static inline t_redirect	*append_redirect(t_redirect **redirect)
{
	int			i;
	t_redirect	*tmp;

	if (*redirect == NULL)
	{
		*redirect = ft_calloc(2, sizeof(t_redirect));
		if (*redirect)
			(*redirect)[1].end = true;
		return (*redirect);
	}
	i = 0;
	while ((*redirect)[i].end != true)
		i++;
	tmp = *redirect;
	*redirect = ft_calloc(i + 2, sizeof(t_redirect));
	ft_memcpy(*redirect, tmp, sizeof(t_redirect) * i);
	free(tmp);
	if (*redirect)
	{
		(*redirect)[i + 1].end = true;
		return ((*redirect) + i);
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
	t_redirect **redirect, char **str, int i, int type)
{
	t_redirect	*new;

	new = append_redirect(redirect);
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

inline void	extract_redirects(t_actions *actions, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == left_corner)
		{
			if (str[i][1] == left_corner)
				do_extract(&actions->args.redirect, str, i, read_input);
			else
				do_extract(&actions->args.redirect, str, i, input);
			i = 0;
		}
		else if (str[i][0] == right_corner)
		{
			if (str[i][1] == right_corner)
				do_extract(&actions->args.redirect, str, i, output_append);
			else
				do_extract(&actions->args.redirect, str, i, output);
			i = 0;
		}
		else
			i++;
	}
}

inline void	add_redirects(t_actions *actions, int type, char *target)
{
	t_redirect	*new;

	new = append_redirect(&actions->args.redirect);
	if (new == NULL)
		return ;
	new->type = type;
	new->target = target;
}
