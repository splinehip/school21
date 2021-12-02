/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:49:58 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/02 16:20:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "input_handler.h"
#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	end;

	(void)env;
	end = 10;
	ft_printf("Hello! Programm name %s, argc: %i%c", argv[0], argc, end);
	input_handler();
	return (0);
}
