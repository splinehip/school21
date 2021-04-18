/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:01:50 by cflorind          #+#    #+#             */
/*   Updated: 2021/04/18 18:47:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

void	*ft_memset(void *buf, int c, size_t l);
void	ft_bzero(void *buf, size_t l);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
