/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:12 by cflorind          #+#    #+#             */
/*   Updated: 2022/05/05 16:37:45 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.h"

Server::Server(char **argv)
    : cfg_file(argv[1] ? argv[1] : DEFCFG)
{
    this->parseCfg();
}

Server::~Server(){};

void    Server::parseCfg(void)
{
    logger::Log &log = logger::Log::getInst();
    log(logger::INFO, "Using configuration file: %s",
        this->cfg_file.c_str());
    this->srvs
        [aton("127.0.0.1")][80]["localhost"]["listen_addr"] = "127.0.0.1";
    this->srvs
        [aton("127.0.0.1")][80]["testhost"]["listen_addr"] = "127.0.0.1";
    std::cout << "listen_addr: "
        << this->srvs[aton("127.0.0.1")][80]["localhost"]["listen_addr"]
        << std::endl;
    std::cout << ntoa(this->srvs.find(aton("127.0.0.1"))->first) << std::endl;
    t_srvs::iterator lsrvs = this->srvs.find(aton("127.0.0.1"));
    if (lsrvs != this->srvs.end())
        std::cout << ntoa(lsrvs->first) << std::endl;
}
