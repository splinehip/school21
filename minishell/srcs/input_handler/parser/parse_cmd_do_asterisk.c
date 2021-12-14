/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_do_asterisk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:21:12 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/14 15:00:42 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

struct s_extract_templates
{
	int		start;
	int		end;
	int		prev_end;
	char	**res;
	char	*pchar;
};

static inline void	free_extracted(char ***extracted)
{
	int	i;

	if (*extracted == NULL)
		return ;
	i = 0;
	while ((*extracted)[i] != NULL)
		free((*extracted)[i++]);
	free(*extracted);
}

static inline int	update_extracted_res(
	struct s_extract_templates *args, char *cmd, char **env)
{
	char	*template_str;
	char	*parsed_str;

	(void)env;
	(void)parsed_str;
	template_str = ft_substr(cmd, args->start, args->end - args->start);
	if (template_str == NULL)
		return (unsucsses);
	ft_printf("ext: %s\n", template_str);
	free(template_str);
	return (sucsses);
}

static inline char	**do_extract(char *cmd, char **env)
{
	struct s_extract_templates	args;

	args.start = 0;
	args.prev_end = 0;
	args.res = NULL;
	args.pchar = ft_strchr(cmd + args.start, asterisk);
	while (args.pchar)
	{
		args.start = args.pchar - cmd - 1;
		args.end = args.pchar - cmd + 1;
		while (cmd[args.start] != space && args.start - 1 >= 0)
			args.start--;
		while (cmd[args.end] != space)
			args.end++;
		args.prev_end = args.end;
		if (update_extracted_res(&args, cmd, env) == unsucsses)
		{
			free_extracted(&args.res);
			args.res = NULL;
			break ;
		}
		args.pchar = ft_strchr(cmd + args.end + 1, asterisk);
	}
	return (args.res);
}

inline char	*do_parse_whith_asterisk(char *cmd, char **env)
{
	int		i;
	char	*res;
	char	*tmp;
	char	**extracted;

	res = NULL;
	extracted = do_extract(cmd, env);
	i = 0;
	while (extracted && extracted[i])
	{
		tmp = res;
		res = ft_strjoin(res, extracted[i]);
		free(tmp);
		if (res == NULL)
			break ;
		i++;
	}
	free_extracted(&extracted);
	return (res);
}
