/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand_template.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 03:50:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/30 11:57:51 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline int	do_update_res(t_select *args, int ret)
{
	if (pattern_matched(args))
	{
		if ((args->j != 0 || (args->j == 0 && args->res)) && do_update_buf(
				&args->res, " ", &args->buf[0], &args->j) == unsuccess)
			return (unsuccess);
		if (do_update_buf(
				&args->res, args->d_name, &args->buf[0], &args->j) == unsuccess)
			return (unsuccess);
		return (success);
	}
	else if (ft_strncmp("./", args->templated_strs[0], 2) == 0)
	{
		args->d_name = ft_strjoin("./", args->d_name);
		if (pattern_matched(args))
		{
			if ((args->j != 0 || (args->j == 0 && args->res)) && do_update_buf(
					&args->res, " ", &args->buf[0], &args->j) == unsuccess)
				ret = unsuccess;
			if (ret == success && do_update_buf(&args->res, args->d_name,
					&args->buf[0], &args->j) == unsuccess)
				ret = unsuccess;
		}
		free(args->d_name);
	}
	return (ret);
}

static inline char	*do_select_item(t_select *args, char **env)
{
	args->j = 0;
	args->res = NULL;
	args->d_name = get_d_name(env);
	while (args->d_name)
	{
		if (do_update_res(args, success) == unsuccess)
			return (NULL);
		args->d_name = get_d_name(env);
	}
	if (args->j != 0)
		do_drop_buf(&args->res, &args->buf[0], &args->j);
	return (args->res);
}

static inline char	*do_templated_select(char *res, char **env)
{
	char		*ret;
	t_select	args;

	if (res == NULL)
		return (NULL);
	do_select_template(res, &args);
	args.templated_strs = ft_split(res, asterisk);
	if (args.templated_strs == NULL)
		return (NULL);
	ret = do_select_item(&args, env);
	while (args.templated_strs[args.j])
		free(args.templated_strs[args.j++]);
	free(args.templated_strs);
	return (ret);
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
				if (do_drop_buf(res, &buf[0], &j) == unsuccess)
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
	res = do_templated_select(res, env);
	free(tmp);
	if (res == NULL)
		return (do_parse(template_str, env));
	return (res);
}
