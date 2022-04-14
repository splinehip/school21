/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:09:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/14 15:42:12 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <cstdarg>
#include <ctime>
#include <string>
#include <deque>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#include "logger/logUtils.h"

namespace logger
{
enum e_levels
{
    INFO,
    WARNING,
    ERROR,
    DEBUG,
    LEVELS_CNT
};

class Log
{
private:
    pthread_t               pth;
    pthread_mutex_t     	mutex_stop;
    int                     pth_stop;
    int                     level;
    std::deque<std::string>	que;
    std::ofstream       	file;

private:
    Log(void){};

    Log(Log const &inst);
    ~Log(void);
    Log	&operator=(Log const &inst);

    void        *operator new(std::size_t);
    void        *operator new[](std::size_t);

    void        operator delete(void *);
    void        operator delete[](void *);

    Log	&start(std::string const &level, std::string const &file_name);

public:
    std::string             	file_name;
    static const std::string	levels[];

public:
    static Log	&getInst(void)
    {
        static Log  log;
        return (log);
    }
    static Log	&init(
        std::string const &level, std::string const &file_name)
    {
        static Log	&log = Log::getInst().start(level, file_name);
        return (log);
    }

    void    setLevel(std::string const &level);
    int     stop(void);
    void    write(int const level, const char *fmt, ...);
    void    do_serialize(void);
};
}
