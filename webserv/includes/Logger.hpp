/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:09:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/07 17:25:59 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LOGGER_H
# define LOGGER_H
# include <string>
# include <deque>
# include <iostream>
# include <fstream>
# include <pthread.h>
# include <string.h>
# include <errno.h>

class Logger
{
private:
	pthread_t				pth;
	int						level;
	std::deque<std::string>	que;
	std::ofstream			file;

private:
	Logger(void);

public:
	Logger(std::string &level, std::string &file_name);
	Logger(Logger const &inst);
	~Logger(void);

	Logger	&operator=(Logger const &inst);
};

void	operator<<(std::istream &is, std::string msg);

#endif
