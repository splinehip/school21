/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:25:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 12:05:00 by cflorind         ###   ########.fr       */
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
	int		j;
	char	*next;

	i = 0;
	if (match_only_start(args))
	{
		next = args->d_name + ft_strlen(args->templated_strs[i]);
		i++;
		while (args->templated_strs[i])
		{
			if (next >= args->d_name + ft_strlen(args->d_name))
				return (false);
			ft_printf("next: >%s<, ts: >%s<\n", next, args->templated_strs[i]);
			j = 0;
			while (next[j])
			{
				if (ft_strncmp(next + j++, args->templated_strs[i],
						ft_strlen(args->templated_strs[i])) == 0)
				{
					ft_printf("br, i: %i, j: %i\n", i, j);
					break ;
				}
			}
			if (next[j])
				next += j;
			i++;
		}
		if (args->templated_strs[i] == NULL)
			return (true);
	}
	return (false);
}

inline int	pattern_matched(t_select *args)
{
	if (args->d_name == NULL)
		return (false);
	if (args->direction == only_start)
		return (match_only_start(args));
	if (args->direction == only_end)
		return (match_only_end(args));
	if (args->direction == start_all_end)
		return (match_start_all_end(args));
	return (false);
}
