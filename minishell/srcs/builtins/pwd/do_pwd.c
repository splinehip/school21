/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:37:13 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/07 11:55:41 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "builtins.h"
#include "error_msgs.h"

int		do_pwd(char **env)
{
	char	*wd;

	wd = NULL;
	wd = get_env_value("PWD", env);
	if (!wd)
	{
		ft_printf("%s", ERR_PWD);
		return (1);
	}
	ft_printf("%s\n", wd);
	free(wd);
	return (0);
}
