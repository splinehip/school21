/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:32:09 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/03 13:48:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
s is a pointer to the string to write.
fd is the file descriptor number to write.

Description:
The function writes the given string s to a file with descriptor fd.
*/
void	ft_putstr_fd(const char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}
