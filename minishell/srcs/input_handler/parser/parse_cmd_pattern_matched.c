/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:25:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 15:29:01 by cflorind         ###   ########.fr       */
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
	int		i;
	char	*start;

	i = 0;
	while (args->templated_strs[i + 1])
		i++;
	if (ft_strlen(args->d_name) < ft_strlen(args->templated_strs[i]))
		return (false);
	start = args->d_name + (ft_strlen(args->d_name)
			- ft_strlen(args->templated_strs[i]));
	return (ft_strncmp(start, args->templated_strs[i],
			ft_strlen(args->templated_strs[i])) == 0);
}

static inline t_bool	match_start_all_end(
	t_select *args, int i, char *pd_name, char *next)
{
	if (match_only_start(args))
	{
		next = args->d_name + ft_strlen(args->templated_strs[i++]);
		while (args->templated_strs[i])
		{
			if (args->templated_strs[i + 1] == NULL)
			{
				pd_name = args->d_name;
				args->d_name = next;
				i = match_only_end(args);
				args->d_name = pd_name;
				return (i);
			}
			while (*next != ends && ft_strncmp(next, args->templated_strs[i],
					ft_strlen(args->templated_strs[i])) != 0)
				next++;
			if (*next == ends)
				break ;
			i++;
			next++;
		}
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
		return (match_start_all_end(args, 0, NULL, NULL));
	return (false);
}
