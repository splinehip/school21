/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:09:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/13 22:08:33 by cflorind         ###   ########.fr       */
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
# include <unistd.h>
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

namespace logger
{
	class Log
	{
	private:
		pthread_t				pth;
		pthread_mutex_t			mutex_stop;
		int						level;
		int						pth_stop;
		std::deque<std::string>	que;
		std::ofstream			file;

	private:
		Log(void){};
		Log(Log const &inst);
		Log	&operator=(Log const &inst);

		logger::Log	&run(std::string const &level, std::string const &file_name);

	public:
		std::string					file_name;
		static const std::string	levels[];

	public:
		~Log(void);

		static logger::Log	&inst(void)
		{
			static logger::Log	log;
			return (log);
		}
		static logger::Log	&init(
			std::string const &level, std::string const &file_name)
		{
			static logger::Log	&log = logger::Log::inst().run(level, file_name);
			return (log);
		}

		inline int	stop(void)
		{
			register int	ret;

			pthread_mutex_lock(&this->mutex_stop);
			ret = this->pth_stop && this->que.empty();
			pthread_mutex_unlock(&this->mutex_stop);
			return (ret);
		}

		inline void	setLevel(std::string const &level)
		{
			this->level = 0;
			while (this->level < LEVELS_CNT)
			{
				if (this->levels[this->level] == level)
				{
					return ;
				}
				this->level++;
			}
			std::cerr << "LOGGER: set_level: Invalid level" << std::endl;
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

		inline void	serialize(std::string &msg)
		{
			this->file << msg << std::endl;
		}

		void		write(int const level, const char *fmt, ...);
	};
}

#endif
