/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:23:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/02 16:25:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "input_handler.h"

int	input_handler(void)
{
	printf("symbol: %c (code: %i)\n", quote, quote);
	printf("symbol: %c (code: %i)\n", single_quote, single_quote);
	printf("symbol: %c (code: %i)\n", left_corner, left_corner);
	printf("symbol: %c (code: %i)\n", right_corner, right_corner);
	printf("symbol: %c (code: %i)\n", pipes, pipes);
	printf("symbol: %c (code: %i)\n", env_var, env_var);
	test_func();
	return (0);
}
