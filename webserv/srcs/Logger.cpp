/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:36:42 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/07 17:25:51 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

#define LEVELS_LEN 8

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

std::string	levels[] = {"info", "INFO", "Warning", "WARNING", "Error", "ERROR",
	"Debug", "DEBUG"};

static inline int	levelId(std::string &level)
{
	int	id;

	id = 0;
	while (id < LEVELS_LEN)
	{
		if (levels[id] == level)
			return (id);
		id++;
	}
	return (-1);
}

static inline int	set_level(std::string &level)
{
	int	ret;

	ret = levelId(level);
	if (ret < 0)
	{
		std::cerr << "Invalide logger level" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		return (ret);
}

static void	*serialize(void *_this)
{

}

Logger::Logger(std::string &_level, std::string &file_name)
	: level(set_level(_level))
{
	this->file.open(file_name.c_str(), std::ios::out | std::ios::app);
	if (this->file.is_open() == false)
		std::cerr << "File " << file_name << " open error: " << strerror(errno)
			<< std::endl;
	if (pthread_create(&this->pth, NULL, &serialize, (void *)this) != true)
	{
		std::cerr << "Logger thread creation error: " << strerror(errno)
			<< std::endl;
		exit(EXIT_FAILURE);
	}
}

Logger::Logger(Logger const &inst)
{
}

Logger::~Logger(void)
{
	if (this->file.is_open())
		this->file.close();
}
