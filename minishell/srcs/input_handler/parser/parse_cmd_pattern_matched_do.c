/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched_do.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:02:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 17:06:42 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

inline int	do_match_only_start(t_select *args)
{
	return (ft_strncmp(args->d_name,
			args->templated_strs[0], ft_strlen(args->templated_strs[0])) == 0);
}

inline int	do_match_only_end(t_select *args)
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

inline int	do_match_all_end(t_select *args, int i)
{
	char	*pd_name;
	char	*next;

	next = args->d_name;
	while (args->templated_strs[i])
	{
		if (args->templated_strs[i + 1] == NULL)
		{
			pd_name = args->d_name;
			args->d_name = next;
			i = do_match_only_end(args);
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
	return (false);
}

inline int	do_match_start_all_end(t_select *args)
{
	int		ret;
	char	*pd_name;
	char	*next;

	if (do_match_only_start(args))
	{
		next = args->d_name + ft_strlen(args->templated_strs[0]);
		if (next > args->d_name + ft_strlen(args->templated_strs[0]))
			return (false);
		pd_name = args->d_name;
		args->d_name = next;
		ret = do_match_all_end(args, 1);
		args->d_name = pd_name;
		return (ret);
	}
	return (false);
}
