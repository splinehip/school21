/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:09:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/09 17:47:38 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LOGGER_H
# define LOGGER_H
# include <cstdlib>
# include <cstdarg>
# include <climits>
# include <ctime>
# include <string>
# include <deque>
# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <map>
# include <pthread.h>
# include <string.h>
# include <errno.h>
# define LEVELS_LEN 8

enum e_levels
{
	info,
	INFO,
	Warning,
	WARNING,
	Error,
	ERROR,
	Debug,
	DEBUG,
};

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
	Logger(std::string const &level, std::string const &file_name);
	Logger(Logger const &inst);
	~Logger(void);

	Logger	&operator=(Logger const &inst);

	inline int			getLevel(void);
	inline void			setLevel(std::string const &level);
	inline void			nextMsg(std::string &msg);
	inline int			is_open(void);
	void				write(int const level, const char *fmt, ...);
	inline void			serialize(std::string &msg);
};

#endif
