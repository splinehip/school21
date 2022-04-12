/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:09:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/12 14:54:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LOGGER_H
# define LOGGER_H
# include <cstdlib>
# include <cstdarg>
# include <ctime>
# include <string>
# include <deque>
# include <map>
# include <sstream>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <pthread.h>
# include <string.h>
# include <errno.h>

# include "Logger/loggerUtils.hpp"

enum e_levels
{
	INFO,
	WARNING,
	ERROR,
	DEBUG,
	LEVELS_CNT
};

class Logger
{
private:
	pthread_t				pth;
	int						level;
	std::deque<std::string>	que;
	std::ofstream			file;

public:
	static const std::string	levels[];
	const std::string			file_name;

public:
	Logger(std::string const &level, std::string const &file_name);
	Logger(Logger const &inst);
	~Logger(void);

	Logger	&operator=(Logger const &inst);

	inline void	setLevel(std::string const &level)
	{
		this->level = 0;
		while (this->level < LEVELS_CNT)
		{
			if (this->levels[this->level] == level)
				return ;
			this->level++;
		}
		std::cerr << "LOGGER: Invalide logger level" << std::endl;
		exit(EXIT_FAILURE);
	}
	inline int	getLevel(void)
	{
		return (this->level);
	}
	inline void	nextMsg(std::string &msg)
	{
		msg.clear();
		if (this->que.empty() == false)
		{
			msg = this->que.front();
			this->que.pop_front();
		}
	}
	inline int	is_open(void)
	{
		return (this->file.is_open());
	}
	inline void	serialize(std::string &msg)
	{
		this->file << msg << std::endl;
	}
	void		write(int const level, const char *fmt, ...);
};

#endif
