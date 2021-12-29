/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:37:13 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/29 18:26:58 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "error_msgs.h"

int	do_pwd(char **env)
{
	char	*wd;

	wd = get_env_value("PWD", env);
	if (!wd)
	{
		printf(MSG_ERR_PWD);
		return (1);
	}
	printf("%s\n", wd);
	free(wd);
	return (0);
}
