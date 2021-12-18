/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand_template.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 03:50:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/18 05:38:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline char	*do_template_select(char *res, char **env)
{
	(void)env;
	if (res == NULL)
		return (NULL);
	return (ft_strdup(res));
}

static inline void	do_join(char **res, char *right)
{
	int		j;
	char	*c;
	char	buf[BUF_SIZE];

	j = 0;
	buf[0] = 0;
	c = right;
	while (*res && right && *c != ends)
	{
		if (*c != asterisk || (*c == asterisk && *(c + 1) != asterisk))
		{
			buf[j++] = *c;
			buf[j] = 0;
			if (j == BUF_SIZE)
				if (do_drop_buf(res, &buf[0], &j) == unsucsses)
					return ;
		}
		c++;
	}
	if (j != 0)
		do_drop_buf(res, &buf[0], &j);
}

inline char	*do_expand_template(char *template_str, char **env)
{
	char	*tmp;
	char	*res;
	char	*right;

	if (template_str == NULL)
		return (NULL);
	tmp = ft_strchr(template_str, asterisk);
	res = ft_substr(template_str, 0, tmp - template_str);
	tmp = res;
	res = do_parse(tmp, env);
	free(tmp);
	tmp = ft_strchr(template_str, asterisk);
	right = ft_substr(tmp, 0,
			template_str + ft_strlen(template_str) - template_str);
	tmp = right;
	right = do_parse(right, env);
	free(tmp);
	do_join(&res, right);
	free(right);
	tmp = res;
	res = do_template_select(res, env);
	free(tmp);
	if (res == NULL)
		return (do_parse(template_str, env));
	return (res);
}
