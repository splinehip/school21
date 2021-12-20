/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:25:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 17:35:09 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

inline int	pattern_matched(t_select *args)
{
	if (args->d_name == NULL)
		return (false);
	if (args->direction == single_asterisk && *args->d_name != dot)
		return (true);
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
