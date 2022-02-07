/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:13:33 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/07 12:25:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

char	rgb_idx_name(int i)
{
	if (i == r)
		return ('r');
	else if (i == g)
		return ('g');
	else if (i == b)
		return ('b');
	return ('*');
}

char	axis_idx_name(int i)
{
	if (i == x)
		return ('x');
	else if (i == y)
		return ('y');
	else if (i == z)
		return ('z');
	return ('*');
}
