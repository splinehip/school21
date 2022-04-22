/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:09:14 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/21 16:33:39 by cflorind         ###   ########.fr       */
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
    Log(const std::string &file_name);
    Log(const Log &inst);

    ~Log(void);

    Log     &operator=(const Log &inst);

    void    *operator new(std::size_t);
    void    *operator new[](std::size_t);

    void    operator delete(void *);
    void    operator delete[](void *);

public:
    const std::string           file_name;
    static const std::string    levels[];

public:
    static Log	&getInst(const std::string &file_name = "webserv.log")
    {
        static Log  log(file_name);
        return (log);
    }

    void    setLevel(const std::string &level);
    int     stop(void);
    void    write(const int level, const char *fmt, ...);
    void    do_serialize(void);
};
}
