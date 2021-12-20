/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:25:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 13:18:55 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

static inline t_bool	match_only_start(t_select *args)
{
	return (ft_strncmp(args->d_name,
			args->templated_strs[0], ft_strlen(args->templated_strs[0])) == 0);
}

static inline t_bool	match_only_end(t_select *args)
{
	char	*start;

	if (ft_strlen(args->d_name) < ft_strlen(args->templated_strs[0]))
		return (false);
	start = args->d_name + (ft_strlen(args->d_name)
			- ft_strlen(args->templated_strs[0]));
	return (ft_strncmp(start, args->templated_strs[0],
			ft_strlen(args->templated_strs[0])) == 0);
}

static inline t_bool	match_start_all_end(t_select *args)
{
	int		i;
	char	*next;

	i = 0;
	if (match_only_start(args))
	{
		next = args->d_name + ft_strlen(args->templated_strs[i++]);
		while (args->templated_strs[i] && next
			<= args->d_name + ft_strlen(args->d_name) && *next != ends)
		{
			while (*next != ends)
			{
				if (ft_strncmp(next, args->templated_strs[i],
						ft_strlen(args->templated_strs[i])) == 0)
					break ;
				next++;
			}
			if (*next != ends)
				i++;
			next++;
		}
		if (args->templated_strs[i] == NULL && *next == ends)
			return (true);
	}
	return (false);
}

inline int	pattern_matched(t_select *args)
{
	if (args->d_name == NULL)
		return (false);
	if (args->direction == single_asterisk && *args->d_name != dot)
		return (true);
	if (args->direction == only_start)
		return (match_only_start(args));
	if (args->direction == only_end)
		return (match_only_end(args));
	if (args->direction == start_all_end)
		return (match_start_all_end(args));
	return (false);
}
