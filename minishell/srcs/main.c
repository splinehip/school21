/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:49:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/11/29 15:37:50 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "input_handler.h"
#include "minishell.h"

int	main(int argc, char **argv)
{
	char	end;

	end = 10;
	ft_printf("Hello! Programm name %s, argc: %i%c", argv[0], argc, end);
	input_handler();
	return (0);
}
