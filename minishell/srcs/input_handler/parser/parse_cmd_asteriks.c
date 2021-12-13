/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_asteriks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:21:12 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/13 18:26:15 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bool.h"
#include "input_handler.h"

inline void	add_asteriks_to_expand(char *cmd, t_iter *iter)
{
	if (iter->in_qoutes != false)
		return ;
	if (escaped(cmd, iter->i))
		return ;
}
