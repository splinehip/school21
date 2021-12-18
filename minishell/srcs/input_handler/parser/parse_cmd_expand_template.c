/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand_template.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 03:50:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/18 04:50:58 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

inline char	*do_expand_template(char *template_str, char **env)
{
	char	*c;
	char	*tmp;
	char	*left;
	char	*right;

	if (template_str == NULL)
		return (NULL);
	tmp = ft_strchr(template_str, asterisk);
	left = ft_substr(template_str, 0, tmp - template_str);
	tmp = left;
	left = do_parse(tmp, env);
	free(tmp);
	tmp = ft_strchr(template_str, asterisk);
	right = ft_substr(tmp, 0,
			template_str + ft_strlen(template_str) - template_str);
	tmp = right;
	right = do_parse(right, env);
	free(tmp);
	ft_printf("l: >%s<, r: >%s<\n", left, right);
	c = right;
	while (*c != ends)
	{
		if (*c != asterisk || (*c == asterisk && *(c + 1) != asterisk))
		{
			tmp = left;
			left = ft_strjoinchr(left, *c);
			free(tmp);
		}
		c++;
	}
	free(right);
	if (left == NULL)
		return (do_parse(template_str, env));
	return (left);
}
