/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:23:47 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/06 12:24:06 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "bool.h"
#include "input_handler.h"

int	input_handler(char *cmd, char **env)
{
	parser(cmd, env);
	return (0);
}
