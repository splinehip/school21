/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:33:11 by cflorind          #+#    #+#             */
/*   Updated: 2022/01/27 16:27:05 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H
# ifndef DEBUG
#  define DEBUG 0
# endif
# define LOG_FILE "./rt.log"
# define LOG_INVALARG "miniRT: Invalid arguments number.\n"

void	logger(char *format, ...);

#endif
