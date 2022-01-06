/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:19:45 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/06 15:28:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

#include "mesages.h"
#include "error_msgs.h"
#include "actions_handler.h"

inline int	get_redirect_fd(t_redirect redirect)
{
	int	fd;

	fd = -1;
	if (redirect.type == input)
		fd = open(redirect.target, O_RDONLY);
	else if (redirect.type == output)
		fd = open(redirect.target, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	else if (redirect.type == output_append)
		fd = open(redirect.target, O_WRONLY | O_APPEND | O_CREAT, 0664);
	else
	{
		printf(MSG_ERR_INVRDTYPE);
		return (fd);
	}
	if (fd < 0)
		perror(MSG_PROG_NAME);
	return (fd);
}
