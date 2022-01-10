/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:33:11 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/10 21:18:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "builtins.h"
#include "minishell.h"

int	do_unset(t_action action, char ***env)
{
	int		fd;
	int		i;

	i = 1;
	fd = do_redirects_builtin(action);
	if (fd > 2)
		close(fd);
	if (!action.exec.argv[i] || action.redirect_out.type >= 0)
		return (0);
	while (action.exec.argv[i])
		unset_env(action.exec.argv[i++], *env);
	return (0);
}
