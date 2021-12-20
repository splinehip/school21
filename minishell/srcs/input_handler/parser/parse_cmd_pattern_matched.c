/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:25:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 19:06:08 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

inline void	pattern_matching_get_next(char **next, char *templated_str)
{
	while (**next != ends
		&& ft_strncmp(*next, templated_str, ft_strlen(templated_str)) != 0)
		(*next)++;
}

static inline int	do_match_all_inn_all(t_select *args)
{
	int		i;
	char	*next;

	i = 0;
	next = args->d_name;
	while (args->templated_strs[i])
	{
		pattern_matching_get_next(&next, args->templated_strs[i]);
		if (*next == ends)
			break ;
		i++;
		next++;
	}
	if (args->templated_strs[i] == NULL)
		return (true);
	return (false);
}

inline int	pattern_matched(t_select *args)
{
	if (args->d_name == NULL)
		return (false);
	if (args->direction == single_asterisk && *args->d_name != dot)
		return (true);
	if (args->direction == all_inn_all)
		return (do_match_all_inn_all(args));
	if (args->direction == only_start)
		return (do_match_only_start(args));
	if (args->direction == only_end)
		return (do_match_only_end(args));
	if (args->direction == all_end)
		return (do_match_all_end(args, 0));
	if (args->direction == start_all)
		return (do_match_start_all(args));
	if (args->direction == start_all_end)
		return (do_match_start_all_end(args));
	return (false);
}
