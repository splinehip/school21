/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_do_asterisk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:21:12 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/30 11:57:51 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline int	do_update_res(
	t_extract *args, char *parsed_str, char *template_str)
{
	if (args->j != 0 || (args->j == 0 && args->res != NULL))
		if (do_update_buf(
				&args->res, " ", &args->buf[0], &args->j) == unsuccess)
			return (unsuccess);
	if (*parsed_str != ends)
		if (do_update_buf(
				&args->res, parsed_str, &args->buf[0], &args->j) == unsuccess
			|| do_update_buf(
				&args->res, " ", &args->buf[0], &args->j) == unsuccess)
			return (unsuccess);
	return (do_update_buf(&args->res, template_str, &args->buf[0], &args->j));
}

static inline int	do_extract(t_extract *args, char *cmd, char **env)
{
	int		ret;
	char	*tmp;
	char	*template_str;
	char	*parsed_str;

	ret = unsuccess;
	tmp = ft_substr(cmd, args->prev_end, args->start - args->prev_end);
	parsed_str = do_parse(tmp, env);
	free(tmp);
	template_str = ft_substr(cmd, args->start, args->end - args->start);
	tmp = template_str;
	template_str = do_expand_template(template_str, env);
	free(tmp);
	if (parsed_str != NULL && template_str != NULL)
		ret = do_update_res(args, parsed_str, template_str);
	free(parsed_str);
	free(template_str);
	return (ret);
}

static inline void	do_finalise(char *cmd, t_extract *args, char **env)
{
	int		ret;
	char	*tmp;
	char	*res;

	ret = success;
	if (cmd[args->end] != ends)
	{
		res = ft_substr(cmd, args->end, ft_strlen(cmd) - args->end);
		tmp = res;
		res = do_parse(res, env);
		free(tmp);
		if (ft_strlen(res))
			ret = do_update_buf(&args->res, " ", &args->buf[0], &args->j);
		if (ret == success)
			ret = do_update_buf(&args->res, res, &args->buf[0], &args->j);
		free(res);
	}
	if (ret == success && args->j != 0)
		do_drop_buf(&args->res, &args->buf[0], &args->j);
}

inline char	*do_parse_whith_asterisk(char *cmd, char **env)
{
	t_extract	args;

	args.j = 0;
	args.prev_end = 0;
	args.res = NULL;
	args.pchar = ft_strchr(cmd, asterisk);
	while (args.pchar)
	{
		get_template_border(cmd, &args);
		if (do_extract(&args, cmd, env) == unsuccess)
		{
			if (args.res != NULL)
				free(args.res);
			args.res = NULL;
			break ;
		}
		args.prev_end = args.end;
		args.pchar = ft_strchr(cmd + args.end, asterisk);
		if (args.pchar == NULL)
			do_finalise(cmd, &args, env);
	}
	return (args.res);
}
