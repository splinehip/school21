/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:35:44 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/01 14:02:46 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>

#include "bool.h"
#include "logger.h"

void	logger(char *format, ...)
{
	va_list		ap;
	static int	fd;

	if (fd < 0 || DEBUG == false)
		return ;
	if (fd == false)
	{
		fd = open(LOG_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror("LOGGER");
			return ;
		}
	}
	if (fd > 2)
	{
		va_start(ap, format);
		vdprintf(fd, format, ap);
		va_end(ap);
	}
}
