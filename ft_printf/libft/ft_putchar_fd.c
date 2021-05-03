/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:12:12 by cflorind          #+#    #+#             */
/*   Updated: 2021/05/03 13:48:43 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Arguments:
c - character code for writing.
fd is the file descriptor number to write.

Description:
The function writes the committed character c to file with descriptor fd.
*/
void	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, 1);
}
