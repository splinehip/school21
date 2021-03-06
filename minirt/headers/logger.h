/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:33:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/07 09:43:16 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H
# ifndef DEBUG
#  define DEBUG 0
# endif
# define LOG_FILE "rt.log"

void	logger(char *format, ...);

#endif
