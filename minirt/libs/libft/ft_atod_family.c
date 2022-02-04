/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod_family.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:04:03 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/04 17:04:23 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_strtof(const char *str, char **endptr)
{
	return ((float) ft_strtod(str, endptr));
}

long double	ft_strtold(const char *str, char **endptr)
{
	return (ft_strtod(str, endptr));
}

double	ft_atof(const char *str)
{
	return (ft_strtod(str, NULL));
}
