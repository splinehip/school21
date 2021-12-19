/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_pattern_matched.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:25:41 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/19 22:29:10 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

inline int	pattern_matched(t_select *args)
{
	if (args->d_name)
		return (true);
	return (false);
}
