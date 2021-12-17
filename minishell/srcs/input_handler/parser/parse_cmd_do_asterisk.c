/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_do_asterisk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:21:12 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/17 20:38:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline char	*do_expand_template(char *template_str)
{
	return (ft_strdup(template_str));
}

static inline int	do_update_res(
	t_extract *args, char *parsed_str, char **template_str)
{
	int		ret;
	char	*tmp;

	ret = unsucsses;
	tmp = *template_str;
	*template_str = do_expand_template(*template_str);
	free(tmp);
	if (args->j != 0)
		do_update_buf(" ", (void *)args, pextract, false);
	if (do_update_buf(parsed_str, (void *)args, pextract, false) == sucsses)
		if (do_update_buf(" ", (void *)args, pextract, false) == sucsses)
			ret = do_update_buf(*template_str, (void *)args, pextract, false);
	return (ret);
}

static inline int	do_extract(t_extract *args, char *cmd, char **env)
{
	int		res;
	char	*tmp;
	char	*template_str;
	char	*parsed_str;

	res = sucsses;
	ft_printf("EEE: prev_end: %i, start: %i, end: %i\n",
		args->prev_end, args->start, args->end);
	tmp = ft_substr(cmd, args->prev_end, args->start - args->prev_end);
	parsed_str = do_parse(tmp, env);
	free(tmp);
	template_str = ft_substr(cmd, args->start, args->end - args->start);
	if (parsed_str == NULL || template_str == NULL)
		res = unsucsses;
	ft_printf("ext: parsed_str >%s< template >%s<\n", parsed_str, template_str);
	if (res == sucsses)
		res = do_update_res(args, parsed_str, &template_str);
	free(parsed_str);
	free(template_str);
	return (res);
}

static inline void	do_exit(char *cmd, t_extract *args, char **env)
{
	char	*tmp;
	char	*res;

	if (cmd[args->end] != ends)
	{
		res = ft_substr(cmd, args->end, ft_strlen(cmd) - args->end);
		tmp = res;
		res = do_parse(res, env);
		free(tmp);
		do_update_buf(res, (void *)&args, pextract, false);
		free(res);
	}
	if (args->j != 0)
		do_update_buf(NULL, (void *)args, pextract, true);
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
		if (do_extract(&args, cmd, env) == unsucsses)
		{
			if (args.res != NULL)
				free(args.res);
			args.res = NULL;
			break ;
		}
		args.prev_end = args.end;
		args.pchar = ft_strchr(cmd + args.end, asterisk);
		if (args.pchar == NULL)
			do_exit(cmd, &args, env);
	}
	ft_printf("args->res: >%s< args->end: %i\n", args.res, args.end);
	return (args.res);
}
