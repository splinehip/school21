/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:36:42 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/14 16:06:33 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger/Log.h"

const std::string	logger::Log::levels[] = {
	"INFO", "WARNING", "ERROR", "DEBUG"};

logger::Log::~Log(void)
{
	pthread_mutex_lock(&this->mutex_stop);
	this->pth_stop = true;
	pthread_mutex_unlock(&this->mutex_stop);
	pthread_join(this->pth, NULL);
	this->file.close();
}

logger::Log	&logger::Log::start(
	std::string const &level, std::string const &_file_name)
{
	this->pth_stop = false;
	this->file_name = _file_name;
	this->setLevel(level);
	this->file.open(this->file_name.c_str(), std::ios::app);
	if (this->file.is_open() == false)
	{
		std::cerr << "LGGER: file " << this->file_name << " open error: "
			<< strerror(errno) << std::endl;
	}
	if (pthread_create(&this->pth, NULL, &serializer, (void *)this) != 0)
	{
		std::cerr << "LOGGER: thread creation error: " << strerror(errno)
			<< std::endl;
		exit(EXIT_FAILURE);
	}
	return (*this);
}

void	logger::Log::setLevel(std::string const &level)
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

int		logger::Log::stop(void)
{
	register int	ret;

	pthread_mutex_lock(&this->mutex_stop);
	ret = this->pth_stop && this->que.empty();
	pthread_mutex_unlock(&this->mutex_stop);
	return (ret);
}

void	logger::Log::write(int const level, const char *fmt, ...)
{
	va_list				ap;
	int					size;
	std::string 		msg;

	msg = time_stamp();
	if (level < 0 || level >= LEVELS_CNT)
	{
		std::cerr << "LOGGER: write: invalid level" << std::endl;
		return ;
	}
	if (level > this->level)
	{
		return ;
	}
	msg += levels[level] + ": ";
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

void	logger::Log::do_serialize(void)
{
	std::string	msg;

	while (this->stop() == false)
	{
		if (this->que.empty() == false)
		{
			msg = this->que.front();
			if (this->level > WARNING)
			{
				std::cerr << msg << std::endl;
			}
			else
			{
				std::cout << msg << std::endl;
			}
			this->file << msg << std::endl;
			this->que.pop_front();
		}
		else
		{
			usleep(900);
		}
	}
}
