/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:01:42 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/28 17:07:44 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.h"

namespace cfg
{
Config::Config(char **argv)
    : cfg_file(argv[1] ? argv[1] : "")
{
    logger::Log &log = logger::Log::getInst();
    if (this->cfg_file.empty())
    {
        log(logger::INFO,
            "Config file not set. Using default configuration.");
        this->setDefCfg();
    }
    else
    {
        doParse();
        log(logger::INFO,
            "Configuration file <%s> parsed.", this->cfg_file.c_str());
    }
}

Config::~Config(){};

void    Config::doParse()
{
    logger::Log &log = logger::Log::getInst();
    log(logger::INFO, "Using configuration file: %s.",
        this->cfg_file.c_str());
}
}
