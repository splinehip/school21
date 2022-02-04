/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:10:53 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/04 17:07:56 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "libft.h"
#include "bool.h"
#include "msg_err.h"
#include "logger.h"
#include "input_handler.h"

static inline void	set_value(t_arg *args, char **strs)
{
	char	*end;

	args->ambient.alr = ft_strtod(strs[1], &end);
	logger("ambient.alr: %f\n", args->ambient.alr);
}

void	set_ambient(t_arg *args, char **strs)
{
	int	i;

	if (args->ambient.seted)
	{
		print_err(MSG_NOTUNIQ);
		logger("%s: %s", "set_ambient", MSG_NOTUNIQ);
		exit(unsuccess);
	}
	i = 0;
	while (strs[i])
		i++;
	if (i != 3)
	{
		print_err(MSG_INVSCENEARG);
		logger("%s: args number: %i, %s", "set_ambient", --i, MSG_INVSCENEARG);
		exit(unsuccess);
	}
	set_value(args, strs);
	args->ambient.seted = true;
}
