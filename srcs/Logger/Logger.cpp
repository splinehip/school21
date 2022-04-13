/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:36:42 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/13 16:43:03 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger/Logger.hpp"

const std::string	logger::Log::levels[] = {
	"INFO", "WARNING", "ERROR", "DEBUG"};

logger::Log::~Log(void)
{
	while (this->que.empty() == false);
	this->file.close();
	pthread_join(this->pth, NULL);
}

logger::Log	&logger::Log::run(
	std::string const &level, std::string const &_file_name)
{
	this->file_name = _file_name;
	this->setLevel(level);
	std::cout << this->file_name;
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

void	logger::Log::write(int const level, const char *fmt, ...)
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
