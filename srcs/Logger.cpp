/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:36:42 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/09 17:48:30 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

std::string	levels[] = {"info", "INFO", "Warning", "WARNING", "Error", "ERROR",
	"Debug", "DEBUG"};

std::map<std::ofstream*, std::string> stream_file_table;

static inline std::string	time_stamp(void)
{
	std::ostringstream	strtime;
	std::time_t			t;
	tm					stamp;

	t = time(NULL);
	stamp = *localtime(&t);
	strtime << std::setfill('0') << "["
			<< (stamp.tm_year + 1900) << "."
			<< std::setw(2) << stamp.tm_mon << "."
			<< std::setw(2) << stamp.tm_mday << "_"
			<< std::setw(2) << stamp.tm_hour << ":"
			<< std::setw(2) << stamp.tm_min << ":"
			<< std::setw(2) << stamp.tm_sec << "] ";
	return(strtime.str());
}

static inline int	levelId(std::string const &level)
{
	int	id;

	id = 0;
	while (id < LEVELS_LEN)
	{
		if (levels[id] == level)
			return (id);
		id++;
	}
	return (INT_MAX);
}

static inline int	set_level(std::string const &level)
{
	int	ret;

	ret = levelId(level);
	if (ret == INT_MAX)
	{
		std::cerr << "Invalide logger level" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		return (ret);
}

static void	*serializer(void *_this)
{
	Logger		*log;
	std::string	msg;

	log = reinterpret_cast<Logger *>(_this);
	while (log->is_open())
	{
		log->nextMsg(msg);
		if (msg.size())
		{
			if (log->getLevel() > INFO)
				std::cerr << msg << std::endl;
			else
				std::cerr << msg << std::endl;
			log->serialize(msg);
		}
	}
	exit(EXIT_SUCCESS);
}

Logger::Logger(std::string const &level, std::string const &file_name)
{
	this->level = set_level(level);
	this->file.open(file_name.c_str(), std::ios::app);
	if (this->file.is_open() == false)
		std::cerr << "File " << file_name << " open error: " << strerror(errno)
			<< std::endl;
	stream_file_table[&this->file] = file_name;
	if (pthread_create(&this->pth, NULL, &serializer, (void *)this) != 0)
	{
		std::cerr << "Logger thread creation error: " << strerror(errno)
			<< std::endl;
		exit(EXIT_FAILURE);
	}
}

Logger::Logger(Logger const &inst)
{
	*this = inst;
}

Logger	&Logger::operator=(Logger const &inst)
{
	*this = Logger(levels[inst.level],
		stream_file_table[(std::ofstream *)&inst.file]);
	return (*this);
}

Logger::~Logger(void)
{
	this->file.close();
	pthread_join(this->pth, NULL);
}

inline int			Logger::getLevel(void)
{
	return (this->level);
}

inline void	Logger::setLevel(std::string const &level)
{
	this->level = set_level(level);
}

inline void	Logger::nextMsg(std::string &msg)
{
	msg.clear();
	if (this->que.empty() == false)
	{
		msg = this->que.front();
		this->que.pop_front();
	}
}

int inline	Logger::is_open(void)
{
	return (this->file.is_open());
}

void	Logger::write(int const level, const char *fmt, ...)
{
	va_list				ap;
	int					size;
	std::string 		msg;

	msg = time_stamp();
	if (level < 0 || level > this->level)
	{
		std::cerr << "LOGGER: invalid logger level" << std::endl;
		return ;
	}
	msg += levels[(level % 2 == 0) ? level + 1 : level] + ": ";
	va_start(ap, fmt);
	size = vsnprintf(NULL, 0, fmt, ap);
	va_end(ap);
	if (size <= 0)
	{
		std::cerr << "LOGGER: string formatting error: " << strerror(errno)
			<< std::endl;
		return ;
	}
	va_start(ap, fmt);
	msg.resize(msg.size() + size);
	vsprintf(&msg[msg.size() - size], fmt, ap);
	this->que.push_back(msg);
	va_end(ap);
}

inline void	Logger::serialize(std::string &msg)
{
	this->file << msg << std::endl;
}
