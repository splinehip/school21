/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:47:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/17 22:01:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtolower(char **str)
{
	char	*s;

	if (str == NULL || *str == NULL)
		return ;
	s = *str;
	while (*s != 0)
	{
		*s = ft_tolower(*s);
		s++;
	}
}
