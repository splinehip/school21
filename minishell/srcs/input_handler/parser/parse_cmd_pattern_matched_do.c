/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched_do.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:02:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 19:55:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

inline int	do_match_all_inn_all(t_select *args)
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

inline int	do_match_only(t_select *args, int type)
{
	int		i;
	char	*start;

	if (type == only_start)
		return (ft_strncmp(args->d_name, args->templated_strs[0],
				ft_strlen(args->templated_strs[0])) == 0);
	if (type == only_end)
	{
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
	return (false);
}

inline int	do_match_all_end(t_select *args)
{
	int		i;
	char	*pd_name;
	char	*next;

	i = 0;
	next = args->d_name;
	while (args->templated_strs[i])
	{
		if (args->templated_strs[i + 1] == NULL)
		{
			pd_name = args->d_name;
			args->d_name = next;
			i = do_match_only(args, only_end);
			args->d_name = pd_name;
			return (i);
		}
		pattern_matching_get_next(&next, args->templated_strs[i]);
		if (*next == ends)
			break ;
		i++;
		next++;
	}
	return (false);
}

inline int	do_match_start_all(t_select *args)
{
	int		i;
	char	*next;

	i = 0;
	if (do_match_only(args, only_start))
	{
		next = args->d_name + ft_strlen(args->templated_strs[i]);
		if (next > args->d_name + ft_strlen(args->templated_strs[i++]))
			return (false);
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
	}
	return (false);
}

inline int	do_match_start_all_end(t_select *args)
{
	int		ret;
	char	**ptemplated_strs;
	char	*pd_name;
	char	*next;

	if (do_match_only(args, only_start))
	{
		next = args->d_name + ft_strlen(args->templated_strs[0]);
		if (next > args->d_name + ft_strlen(args->templated_strs[0]))
			return (false);
		pd_name = args->d_name;
		ptemplated_strs = args->templated_strs;
		args->d_name = next;
		args->templated_strs = args->templated_strs + 1;
		ret = do_match_all_end(args);
		args->d_name = pd_name;
		args->templated_strs = ptemplated_strs;
		return (ret);
	}
	return (false);
}
