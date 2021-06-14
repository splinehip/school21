/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintpow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:58:01 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/17 13:28:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulli	ft_uintpow(int nb, int pow)
{
	t_ulli	i;
	t_ulli	res;

	i = 1;
	res = nb;
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (nb);
	while (i < (t_ulli)pow)
	{
		res *= nb;
		i++;
	}
	return (res);
}
