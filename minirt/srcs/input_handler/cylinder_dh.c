/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_dh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:03:50 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/08 14:12:12 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "libft.h"
#include "bool.h"
#include "msg_err.h"
#include "logger.h"
#include "input_handler.h"

inline void	set_cylinder_dh(t_cylinder *cy, char *d, char *h)
{
	cy->d = ft_strtod(d, NULL);
	if (errno == ERANGE)
	{
		print_err(MSG_INVALRANGE);
		logger("cylinder.d: %f, >%s<: %s\n", cy->d, d, strerror(errno));
		exit(unsuccess);
	}
	logger("cylinder.d: %f\n", cy->d);
	cy->h = ft_strtod(h, NULL);
	if (errno == ERANGE)
	{
		print_err(MSG_INVALRANGE);
		logger("cylinder.h: %f, >%s<: %s\n", cy->d, h, strerror(errno));
		exit(unsuccess);
	}
	logger("cylinder.h: %f\n", cy->h);
}
